#include "spriteset.hpp"
#include "textureloader.hpp"
#include "log.hpp"

using video::Sprite;

SpriteSet::~SpriteSet() {
  clearCache();
}

bool SpriteSet::load() {
  //loader->loadTextures();
  //std::map<string, std::vector<Sprite*>> spriteloader->getSprites(name);
  return true;
}

void SpriteSet::unload() {
  clearCache();
}

void SpriteSet::clearCache() {
  for (auto group : animatedSprites) {
    for (auto item : group.second) {
      SDL_FreeSurface(item->image);
      delete item;
    }
  }
  animatedSprites.clear();
  for (auto item : staticSprites) {
    SDL_FreeSurface(item.second->image);
    delete item.second;
  }
  staticSprites.clear();
}

void SpriteSet::setName(const char* name) {
  this->name = name;
}

void SpriteSet::setLoader(TextureLoader* loader) {
  this->loader = loader;
}

Sprite* SpriteSet::getSpriteFromGroup(const std::string& name, int ingroupNum) {
  return getSpriteFromGroup(name.c_str(), ingroupNum);
}

Sprite* SpriteSet::getSpriteFromGroup(const char* name, int ingroupNum) {
  auto it = animatedSprites.find(name);
  if (it == animatedSprites.end()) {
    LOG_MSG("Wrong sprite name " << name);
    return NULL;
  }
  return it->second[ingroupNum];
}

video::Sprite* SpriteSet::getSpriteByName(const std::string& name) {
  return getSpriteByName(name.c_str());
}

video::Sprite* SpriteSet::getSpriteByName(const char* name) {
  auto it = staticSprites.find(name);
  if (it == staticSprites.end()) {
    LOG_MSG("Wrong sprite name " << name);
    return NULL;
  }
  return it->second;
}

Sprite* SpriteSet::getLetter(const char name) {
  char copy[] = {name, '\0'};
  return getSpriteByName(copy);
}

void SpriteSet::addGroupSprite(std::string spriteSetName, video::Sprite* sprite) {
  animatedSprites[spriteSetName].push_back(sprite);
}

void SpriteSet::addStaticSprite(std::string spriteName, video::Sprite* sprite) {
  staticSprites[spriteName] = sprite;
}
