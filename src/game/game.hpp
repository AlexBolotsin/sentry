#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>
#include "ilistener.hpp"

namespace application {

class Scene;

class Game : public IListener {
  bool enabled;
  // map of screens
public:
  Game();
  void run();
  void listen(IMessage* msg);
  void setName(const char* name);
  void addScene(Scene* scene);

private:
  Uint32 timer;
  void startTimer();
  Uint32 getDiff();
};

};

#endif