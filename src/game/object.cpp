#include "object.hpp"
#include "spriteset.hpp"
#include "render.hpp"
#include "log.hpp"

bool Object::load() {
  LOG_MSG("Loading object " << name);
  return false;
}

void Object::unload() {
  LOG_MSG("Droping set");
}

void Object::update(int diff) {
}

void Object::setName(const char* name ) {
  this->name = name;
}

void Object::setSpriteSet(const char* set) {
  this->set = set;
}

void Object::setAnimationSet(const char* set) {
  group = set;
}

void Object::move(Map* map) {
  
}

void Object::setMovement(Movement movement) {
  this->movement |= movement;
}

void Object::unregMovement(Movement movement) {
  this->movement ^= movement;
}
