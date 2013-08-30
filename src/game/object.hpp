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
    MOVE_NONE = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT
  };
private:
  /* THIS ONE IS FCUKING DUMB!!!! Oh man. */
  bool moveDirections[4];
  SpriteSet* set;
  video::Sprite* sprite;
  std::string name;
  std::string group;
public:

  /* so here we go - it know specific ScripeSet to get some sprites,
     so when it really needs it ask SpriteSet about geting it from disk.
     Simple but not so much.
   */
  bool load();
  /* Do you really wanna know? */
  void unload();
  /* Updates some logic and animations. */
  void update(int diff);
  /* I'm tired describing this setName procedures. */
  void setName(const char* name);
  /* We need to have only sprite set name */
  void setSpriteSet(const char* set);
  /* I don't know how to use it. But it holds a point. */
  void setAnimationSet(const char* set);
  /* I uses it in input handler to direct an object and then at map update move it */
  void move(Movement movement);
  /* that is dumb */
  void unregMove(Movement movement);
};

#endif
