#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace video {
  struct Sprite;
};

class SpriteSet;

class Object {
  SpriteSet* set;
  video::Sprite* sprite;
  const char* name;
  const char* group;
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
