#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>
#include <list>
#include "ilistener.hpp"

namespace core {

class Scene;

class Game : public IListener {
  bool enabled;
  std::list<Scene*> scenes;
  Scene* current;
  // map of screens
  Uint32 timer;

public:
  Game();
  void run();
  void listen(IMessage* msg);
  void setName(const char* name);
  void addScene(Scene* scene);
  int exitCode();

private:
  int exit;
  int fps;
  void startTimer();
  Uint32 getDiff();
};

};

#endif
