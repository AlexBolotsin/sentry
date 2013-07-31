#include "spriteset.hpp"
#include "textureloader.hpp"
#include "log.hpp"

bool SpriteSet::load() {
  loader->loadTextures();
  //std::map<string, std::vector<Sprite*>> spriteloader->getSprites(name);
  return true;
}

void SpriteSet::unload() {
  loader->clearCache();
}

void SpriteSet::setName(const char* name) {
  this->name = name;
}

void SpriteSet::setDefault(const char* def) {
  LOG_MSG("Default sprite setted to " << def);
  this->def = def;
  LOG_MSG(this->def);
}

void SpriteSet::setLoader(TextureLoader* loader) {
  this->loader = loader;
}

video::Sprite* SpriteSet::getSprite(const char* group, int id) {
  return NULL;
}

video::Sprite* SpriteSet::getDefault() {
  return loader->getSpriteByName(def);
}
