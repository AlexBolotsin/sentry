#include "textureloader.hpp"

#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include "log.hpp"

using video::Sprite;

TextureLoader::TextureLoader() : scale(1) {
}

TextureLoader::~TextureLoader() {
  Log::detail("Drop TextureLoader");
  clearCache();
}

void TextureLoader::setName(const char* filename) {
  this->filename = filename;
}

Sprite* TextureLoader::getSpriteByName(const std::string& name) {
  return getSpriteByName(name.c_str());
}

Sprite* TextureLoader::getSpriteByName(const char* name) {
  auto it = sprites.find(name);
  if (it == sprites.end()) {
    LOG_MSG("Wrong sprite name " << name);
    return NULL;
  }
  return it->second;
}

Sprite* TextureLoader::getSpriteByName(const char name) {
  char copy[] = {name, '\0'};
  return getSpriteByName(copy);
}

void TextureLoader::loadTextures() {
  SDL_Surface* image = NULL;
  if (!loadImage(image) && !image) return;
  
  SDL_Surface* tmp = image;
  image = SDL_DisplayFormat(image);
  if (!image)
    Log::error("Can't convert image to display format");
  SDL_FreeSurface(tmp);
  
  TiXmlDocument doc;
  if (!loadXML(doc)) return;
  
  TiXmlElement* element = doc.FirstChildElement()->FirstChildElement("item");
  if (!element) {
    Log::error("Can't find item");
    return;
  }

  //clearCache();
  
  while (element) {
    std::string name;
    element->QueryStringAttribute("name", &name);
    Log::detail(name.c_str());
    if (sprites.find(name) == sprites.end()) {
      Sprite* sprite = new Sprite();
      element->QueryIntAttribute("x", &sprite->x);
      element->QueryIntAttribute("y", &sprite->y);
      element->QueryIntAttribute("width", &sprite->w);
      element->QueryIntAttribute("height", &sprite->h);
      cutPiece(image, sprite);
      sprites[name] = sprite;
    } else {
      Log::detail("Avoided reading sprite once more");
    }

    element = element->NextSiblingElement();
  }
  SDL_FreeSurface(image);
}

void TextureLoader::clearCache() {
  for (auto item : sprites) {
    SDL_FreeSurface(item.second->image);
    delete item.second;
  }
  sprites.clear();
}

void TextureLoader::cutPiece(SDL_Surface* source, Sprite* sprite) {
  sprite->image = SDL_CreateRGBSurface(0, sprite->w,
				       sprite->h, 32, 0, 0, 0, 0);
  SDL_SetColorKey(sprite->image, SDL_SRCCOLORKEY | SDL_RLEACCEL,
		  SDL_MapRGB(sprite->image->format, 255, 0, 255));
  SDL_Rect source_rect = {sprite->x, sprite->y, sprite->w, sprite->h};
  SDL_Rect dest_rect = {0, 0, sprite->w, sprite->h};
  SDL_BlitSurface(source, &source_rect, sprite->image, &dest_rect);
    rescale(sprite);
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
