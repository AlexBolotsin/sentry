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
  std::string name;
  std::string def;
  TextureLoader* loader;
  std::list<std::string> sprites;
  int currSpriteNum;
  
public:
  bool load();
  void unload();
  void setName(const char* name);
  void setLoader(TextureLoader* loader);
  video::Sprite* getSprite(const char* group, int id);
  video::Sprite* getDefault();
};

#endif
