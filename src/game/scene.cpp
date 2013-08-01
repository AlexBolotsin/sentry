#include "scene.hpp"
#include "render.hpp"
#include "object.hpp"
#include "map.hpp"
#include "log.hpp"
#include "messages.hpp"
#include "keypressed.hpp"
#include "keyreleased.hpp"

using application::Scene;

Scene::Scene() : isReady(false) {
}

void Scene::setName(const char* name) {
  this->name = name;
}

void Scene::render(video::Render* render) {
  render->render(map);
  /*
    map->getBackground();
    for (object* obj : map->getObjects(), camera)
      render->(obj->getSprite());
   */  
}

void Scene::update(int diff) {
}

bool Scene::load() {
  isReady = map->load();
  return isReady;
}

void Scene::unload() {
  LOG_MSG("Droping map");
  map->unload();
  isReady = false;
}

bool Scene::ready() {
  return isReady;
}

void Scene::setMap(Map* map) {
  LOG_MSG("Set map");
  this->map = map;
}

Map* Scene::getMap() {
  return map;
}

void Scene::listen(IMessage* msg) {
  switch (msg->type()) {
  case message::MSG_KEY_PRESSED: {
    message::KeyPressed* press = dynamic_cast<message::KeyPressed*>(msg);
    LOG_MSG("Pressed key " << press->getKey());
    break;
  }
  case message::MSG_KEY_RELEASED: {
    message::KeyReleased* release = dynamic_cast<message::KeyReleased*>(msg);
    LOG_MSG("Released key " << release->getKey());
    break;
  }
  default:
    break;
  }
}
