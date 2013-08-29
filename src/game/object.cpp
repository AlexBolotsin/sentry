#include "object.hpp"
#include "spriteset.hpp"
#include "render.hpp"
#include "log.hpp"

bool Object::load() {
  LOG_MSG("Loading object " << name);
  return set->load();
}

void Object::unload() {
  LOG_MSG("Droping set");
  set->unload();
}

void Object::update(int diff) {
  sprite = set->getSprite(group.c_str(), 0);
}

void Object::setName(const char* name ) {
  this->name = name;
}

void Object::setSpriteSet(SpriteSet* set) {
  this->set = set;
}

void Object::setAnimationSet(const char* set) {
  group = set;
}

video::Sprite* Object::getSprite() {
  return set->getDefault();
}

void Object::move(Movement movement) {
  moveDirections[movement] = true;
}

void Object::dontMove(Movement movement) {
  moveDirections[movement] = false;
}

void Object::spriteSet(const char* set) {
}
