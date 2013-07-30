#ifndef SPRITE_SET_HPP
#define SPRITE_SET_HPP

#include <string>
#include <list>
namespace video {
  struct Sprite;
};

class TextureLoader;

class SpriteSet {
  // sprites groups
  // list of sprites
  const char* name;
  TextureLoader* loader;
  std::list<std::string> groups;
  
public:
  bool load();
  void unload();
  void setName(const char* name);
  void setLoader(TextureLoader* loader);
  video::Sprite* getSprite(const char* group, int id);
  video::Sprite* getDefault();
};

#endif
