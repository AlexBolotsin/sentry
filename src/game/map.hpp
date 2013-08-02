#ifndef MAP_HPP
#define MAP_HPP

#include <list>
#include <vector>
#include "render.hpp"
#include "spriteset.hpp"
#include "object.hpp"

class Map {
  const char* name;
  SpriteSet* set;
  int width, height;
  video::Sprite* def_sprite;
  std::list<Object*> objects;
  Object* player_cell;
  int offset_x, offset_y;
  std::vector<video::Sprite*> grid;
  
public:
  Map();
  ~Map();

  void update(int diff);
  bool load();
  void unload();
  void render(video::Render* render);
  void setName(const char* name);
  void setSpriteSet(SpriteSet* set);
  void setSize(int width, int height);
  void size(int& width, int& heigth);
  void setOffset(int x, int y);
  void offset(int& x, int& y);
  int tileSize();
  video::Sprite* cellAt(int x, int y);
};

#endif
