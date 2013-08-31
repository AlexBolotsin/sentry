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

Game::Game() : enabled(true), currentScene(NULL), timeCounter(0), exitCode(0), fpsCount(0) {
}

void Game::run() {
  video::Render render;
  if (!render.init()) {
    Log::error("FAILED INIT RENDER");
    exitCode = 1;
    return;
  }

  EmitterSwitch switcher;
  input::Input input;
  input.setListener(&switcher);
  switcher.addListener(this);
  switcher.addListener(currentScene);
  bool result = currentScene->load();
  if (!result) {
    exitCode = 1;
    return;
  }
  while (enabled) {
    startTimer();
    while (getDiff() < 1000 / FPS) {
        fpsCount++;
    }
    LOG_MSG("Current fps is " << fpsCount);
    fpsCount = 0;
    input.processInput();
    currentScene->update(getDiff());
    render.clear();
    currentScene->render(&render);
    render.draw();
  }
}

void Game::startTimer() {
  timeCounter = SDL_GetTicks();
}

Uint32 Game::getDiff() {
  return SDL_GetTicks() - timeCounter;
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
  if (!currentScene) currentScene = scene;
  scenes.push_back(scene);
}

int Game::getExitCode() {
  return exitCode;
}
