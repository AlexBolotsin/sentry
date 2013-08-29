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
  enum Movement {
    MOVE_NONE = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT
  };
private:
  bool moveDirections[4];
  SpriteSet* set;
  video::Sprite* sprite;
  std::string name;
  std::string group;
public:

  bool load();
  void unload();
  void update(int diff);
  void setName(const char* name);
  void setSpriteSet(SpriteSet* set);
  void spriteSet(const char* set);
  void setAnimationSet(const char* set);
  video::Sprite* getSprite();
  void move(Movement movement);
  void dontMove(Movement movement);
};

#endif
