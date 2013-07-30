#include "game.hpp"
#include "log.hpp"
#include "input.hpp"
#include "scene.hpp"
#include "render.hpp"
#include "emitterswitch.hpp"
#include "messages.hpp"

#define FPS 45

using application::Game;
using application::Scene;

Game::Game() : enabled(true), timer(0) {
}

void Game::run() {
  video::Render render;
  if (!render.init()) {
    Log::error("FAILED INIT RENDER");
    return;
  }

  EmitterSwitch switcher;
  input::Input input;
  input.setListener(&switcher);
  switcher.addListener(this);
  application::Scene scene;
  scene.load();
  while (enabled) {
    startTimer();
    while (getDiff() < 1000 / FPS) {}
    input.processInput();
    scene.update(getDiff());
  }
}

void Game::startTimer() {
  timer = SDL_GetTicks();
}

Uint32 Game::getDiff() {
  return SDL_GetTicks() - timer;
}

void Game::listen(IMessage* msg) {
  if (msg->type() != message::MSG_QUIT) return;
  Log::detail("Game got message");
  enabled = false;
}

void Game::addScene(Scene* scene) {
}