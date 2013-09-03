#ifndef SPRITE_SET_HPP
#define SPRITE_SET_HPP

#include <string>
#include <list>
#include <map>
#include <vector>
#include "render.hpp"

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
  int currSpriteNum;
  std::map<std::string, video::Sprite*> staticSprites;
  std::map<std::string, std::vector<video::Sprite*>> animatedSprites;
  
  void clearCache();

public:
  ~SpriteSet();
  video::Sprite* getSpriteFromGroup(const std::string& name, int ingroupNum);
  video::Sprite* getSpriteFromGroup(const char* name, int ingroupNum);
  video::Sprite* getSpriteByName(const std::string& name);
  video::Sprite* getSpriteByName(const char* name);
  video::Sprite* getLetter(const char name);

  bool load();
  void unload();
  void setName(const char* name);
  void setLoader(TextureLoader* loader);
  void addGroupSprite(std::string spriteSetName, video::Sprite* sprite);
  void addStaticSprite(std::string spriteName, video::Sprite* sprite);
};

#endif
