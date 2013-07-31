#include "scene.hpp"
#include "render.hpp"
#include "object.hpp"
#include "map.hpp"
#include "log.hpp"

using application::Scene;

Scene::Scene() : isReady(false) {
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
