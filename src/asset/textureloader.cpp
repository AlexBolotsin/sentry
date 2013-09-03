#include "textureloader.hpp"

#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include "log.hpp"

std::map<std::string, TextureLoader*> TextureLoader::loaders;

using video::Sprite;

TextureLoader::TextureLoader() : scale(1) {
}

TextureLoader::~TextureLoader() {
}

void TextureLoader::dropLoaders() {
  Log::detail("Drop TextureLoader");
  for (auto loaderItr : loaders)
    delete loaderItr.second;
}

TextureLoader* TextureLoader::getLoader(std::string loaderName) {
  auto loaderItr = loaders.find(loaderName);
  if (loaderItr == loaders.end()) {
    TextureLoader* loader = new TextureLoader();
    loader->setName(loaderName.c_str());
    loaders[loaderName] = loader;
    loaderItr = loaders.find(loaderName);
  }
  return loaderItr->second;
}

void TextureLoader::setName(const char* filename) {
  this->filename = filename;
}

SpriteSet* TextureLoader::loadTextureGroup(std::string groupName) {
  SDL_Surface* image = NULL;
  if (!loadImage(image) && !image) return NULL;
  
  SDL_Surface* tmp = image;
  image = SDL_DisplayFormat(image);
  if (!image)
    Log::error("Can't convert image to display format");
  SDL_FreeSurface(tmp);
  
  TiXmlDocument doc;
  if (!loadXML(doc)) return NULL;
  
  TiXmlElement* xmlGroup = doc.FirstChildElement()->FirstChildElement();

  while(xmlGroup) {
    std::string xmlGroupName;
    xmlGroup->QueryStringAttribute("name", &xmlGroupName);
    LOG_MSG(xmlGroupName);
    if (xmlGroupName == groupName) break;
    xmlGroup = xmlGroup->NextSiblingElement();
  }

  if (!xmlGroup) {
    LOG_MSG("No such group.");
    return NULL;
  }

  SpriteSet* resultingSpriteSet = new SpriteSet;
  TiXmlElement* xmlSpriteSet = xmlGroup->FirstChildElement();
  while (xmlSpriteSet) {
    std::string xmlSpriteSetName;
    xmlSpriteSet->QueryStringAttribute("name", &xmlSpriteSetName);
    int xmlSpriteSetType = 0;
    xmlSpriteSet->QueryIntAttribute("type", &xmlSpriteSetType);
    TiXmlElement* xmlItem = xmlSpriteSet->FirstChildElement();
    while (xmlItem) {
      std::string xmlItemName;
      xmlItem->QueryStringAttribute("name", &xmlItemName);
      Sprite* sprite = new Sprite();
      xmlItem->QueryIntAttribute("x", &sprite->x);
      xmlItem->QueryIntAttribute("y", &sprite->y);
      xmlItem->QueryIntAttribute("width", &sprite->w);
      xmlItem->QueryIntAttribute("height", &sprite->h);
      cutPiece(image, sprite);
      if (xmlSpriteSetType == 0)
	resultingSpriteSet->addStaticSprite(xmlItemName, sprite);
      else 
	resultingSpriteSet->addGroupSprite(xmlSpriteSetName, sprite);
      xmlItem = xmlItem->NextSiblingElement();
    }
    xmlSpriteSet = xmlSpriteSet->NextSiblingElement();
  }
  SDL_FreeSurface(image);

  return resultingSpriteSet;
}

void TextureLoader::cutPiece(SDL_Surface* source, Sprite* sprite) {
  sprite->image = SDL_CreateRGBSurface(0, sprite->w,
				       sprite->h, 32, 0, 0, 0, 0);
  SDL_SetColorKey(sprite->image, SDL_SRCCOLORKEY | SDL_RLEACCEL,
		  SDL_MapRGB(sprite->image->format, 255, 0, 255));
  SDL_Rect source_rect = {(Sint16)sprite->x, (Sint16)sprite->y, (Uint16)sprite->w, (Uint16)sprite->h};
  SDL_Rect dest_rect = {0, 0, (Uint16)sprite->w, (Uint16)sprite->h};
  SDL_BlitSurface(source, &source_rect, sprite->image, &dest_rect);
}

void TextureLoader::rescale(Sprite* sprite) {
  SDL_Surface* tmp = sprite->image;
  sprite->image = rotozoomSurface(sprite->image, 0, scale, 0);
  sprite->w *= scale;
  sprite->h *= scale;
  SDL_FreeSurface(tmp);
}

bool TextureLoader::loadImage(SDL_Surface*& image) {
  IMG_Init(IMG_INIT_PNG);
  image = IMG_Load(std::string(filename).append(".png").c_str());
  IMG_Quit();
  if (!image) {
    Log::error(std::string("Can't load image file ").append(filename).c_str());
      return false;
  }
  return true;
}

bool TextureLoader::loadXML(TiXmlDocument& doc) {
  if (!doc.LoadFile(std::string(filename).append(".xml"))) {
    Log::error(std::string("Can't load xml file ").append(filename).c_str());
    return false;
  }
  return true;
}
