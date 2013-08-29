#ifndef SCENE_HPP
#define SCENE_HPP

#include "render.hpp"
#include "ilistener.hpp"
#include <string>

class Object;
class Map;

namespace core {

class Scene : public IListener {
  Map* map;
  bool isReady;
  std::string name;
public:
  Scene();
  /* IT IS FCUKING DUMB. Why do I needs it here?
     For God sake I have to do smth about it.
     Gosh man.
     It sucks... I guess render should have it's own logic to being able draw stuff... Or it's not?
     I don't give a fcuk
     I'll be back
   */
  void render(video::Render* render);
  /* You can set name of the scene. Useful for debug(?). */
  void setName(const char* name);
  /* It does a lot, you know. It moves stuff, updates animations and stuff.
     Describe it more!
   */
  void update(int diff);
  /* This is ointeresting one. The whole idea is in loading resources when it used in the fisrt time.
     Also it returns false at some error and true if all right.
   */
  bool load();
  /* In opposite to prev prosedure this one does unloads resources.
     So the whole thing is: Switch scenes - unload old one, load new one. Profit: low memory usage.
   */
  void unload();
  /* Shows status of loading stuff. */
  bool ready();
  /* Now you have to set up map to load up... Needs more research. 
   */
  void setMap(Map* map);
  Map* getMap();
  /* Just as it is in Game it looks for some events, specially it what's key pressed and released.
     It used to move map and player sprite.
   */
  void listen(IMessage* msg);
  /* So now when I'm a little bit tipsy I would like to keep watching LGR reviews. Even when this nice 
     roommate's friend (which is girl) is here.
     FCUK IT.
  */
};

};

#endif
