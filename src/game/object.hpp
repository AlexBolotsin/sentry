#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

namespace video {
  struct Sprite;
};

class SpriteSet;

class Object {
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
  void setAnimationSet(const char* set);
  video::Sprite* getSprite();
};

#endif
