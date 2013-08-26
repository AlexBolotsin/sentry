#include "fakeloader.hpp"
#inlcude "game.hpp"

using core::Game;
using core::Scene;

Game* FakeLoader::load() {
  Game* game = new Game();

  Scene* scene = new Scene();
  Object* obj = new Object();
  obj->setName("Alex");
  obj->spriteSet("marry");
  scene->addObject(obj);
  MoveHandler* handler = new MoveHandler();
  handler->target(obj);
  scene->addListener(handler);
  return game;
}
