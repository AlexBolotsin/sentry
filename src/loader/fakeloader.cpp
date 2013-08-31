#include "fakeloader.hpp"
#include "object.hpp"
#include "map.hpp"

using core::Game;
using core::Scene;

Game* FakeLoader::load() {
  Game* game = new Game();

  Scene* scene = new Scene();
  Object* obj = new Object();
  obj->setName("Alex");
  obj->setSpriteSet("marry");
  Map* map = new Map();
  scene->setMap(map);
  map->addObject(obj, 0, 0);
  MoveHandler* handler = new MoveHandler();
  handler->target(obj);
  scene->setListener(handler);
  return game;
}
