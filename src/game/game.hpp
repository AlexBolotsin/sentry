#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>
#include <list>
#include "ilistener.hpp"

namespace core {
  class Scene;

class Game : public IListener {
  bool enabled;
  /* Here are lied all scenes used in a game.
     Is it fine? don't think so. */
  std::list<core::Scene*> scenes;
  /* Current scene. Used in main loop. */
  Scene* currentScene;
  // map of screens
  Uint32 timeCounter;

public:
  Game();
  /* so yeah there is our main loop in which we will
     handle input,
     update game scene,
     redraw it and so on.
     Also we have to count fps and such stuff here.
   */
  void run();
  /* well it's probably wrong that procedure is here.
     it needs some more researching.
     it listens for only one msg which is quit...
     Yeah it's al ittle bit awkward. However.
   */
  void listen(IMessage* msg);
  /* Seting name of the game. Can be useful in near future for
     window title name and something else. 
   */
  void setName(const char* name);
  /* I don't give a fuck why it's here.
     I have to make some point of it being there.
   */
  void addScene(Scene* scene);
  /* Returns error code. Simple as fuck.
   */
  int getExitCode();

private:
  int exitCode;
  int fpsCount;
  /* starts timer in main loop. Should I really keep it here? */
  void startTimer();
  /* Diff counter. It subtracts current time and saved one to find out it's differenc.
     Saved one in member.
  */
  Uint32 getDiff();
};

};
#endif
