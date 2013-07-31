#ifndef MAP_HPP
#define MAP_HPP

#include <list>
#include <vector>
#include "render.hpp"
#include "spriteset.hpp"
#include "object.hpp"

class Map {
  struct Cell {
    std::list<Object*> objects;
    video::Sprite* sprite;
  };

  const char* name;
  SpriteSet* set;
  int width, height;
  video::Sprite* def_sprite;
  std::list<Object*> objects;
  int offset_x, offset_y;
  std::vector<Cell> grid;
  
public:
  Map();
  ~Map();

  void update(int diff);
  bool load();
  void unload();
  void render(video::Render* render);
  void addObject(Object* obj, int x, int y);
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
