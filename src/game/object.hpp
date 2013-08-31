#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include "movehandler.hpp"

namespace video {
  struct Sprite;
};

class SpriteSet;

class Object {
public:
  /* Helps describe object's direction. */
  enum Movement {
    MOVE_NONE = 0x0,
    MOVE_UP = 0x1,
    MOVE_DOWN = 0x2,
    MOVE_RIGHT = 0x4,
    MOVE_LEFT = 0x8
  };
private:
  /* THIS ONE IS FCUKING DUMB!!!! Oh man. */
  int movement;
  SpriteSet* set;
  video::Sprite* sprite;
  std::string name;
  std::string group;
  Map* map;
  int speed;
public:
  /* so here we go - it know specific ScripeSet to get some sprites,
     so when it really needs it ask SpriteSet about geting it from disk.
     Simple but not so much.
   */
  bool load();
  /* Do you really wanna know? */
  void unload();
  /* Updates some logic and animations. And move on a map. */
  void update(int diff);
  /* I'm tired describing this setName procedures. */
  void setName(const char* name);
  /* We need to have only sprite set name */
  void setSpriteSet(const char* set);
  /* I don't know how to use it. But it holds a point. */
  void setAnimationSet(const char* set);
  /* So I've decided to move an object on map update and move it with it's speed and direction.
     I'll try to deal with it as it is for now. I need some tests to get a point.
  */
  void move(Map* map);
  /* I uses it in input handler to direct an object and then at map update move it */
  void setMovement(Movement movement);
  /* that is dumb */
  void unregMove(Movement movement);
};

#endif
