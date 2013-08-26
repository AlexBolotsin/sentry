#include "game.hpp"
#include "log.hpp"
#include "input.hpp"
#include "scene.hpp"
#include "render.hpp"
#include "emitterswitch.hpp"
#include "messages.hpp"

#define FPS 45

using core::Game;
using core::Scene;

Game::Game() : enabled(true), current(NULL), timer(0), fps(0), exit(0) {
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
  switcher.addListener(current);
  current->load();
  while (enabled) {
    startTimer();
    while (getDiff() < 1000 / FPS) {
        fps++;
    }
    LOG_MSG("Current fps is " << fps);
    fps = 0;
    input.processInput();
    current->update(getDiff());
    render.clear();
    current->render(&render);
    render.draw();
  }
}

void Game::startTimer() {
  timer = SDL_GetTicks();
}

Uint32 Game::getDiff() {
  return SDL_GetTicks() - timer;
}

void Game::listen(IMessage* msg) {
  if (msg->type() == message::MSG_QUIT) {
    Log::detail("Game got message");
    enabled = false;
  }
  if (listener)
    listener->listen(msg);
}

void Game::addScene(Scene* scene) {
  if (!current) current = scene;
  scenes.push_back(scene);
}

int Game::exitCode() {
  return exit;
}
