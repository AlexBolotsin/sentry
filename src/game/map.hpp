#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <vector>
#include "render.hpp"
#include "spriteset.hpp"
#include "object.hpp"

class Map {
  std::string name;
  int width, height;
  int offset_x, offset_y;
  std::vector<int> grid;
  
public:
  Map();
  ~Map();

  void update(int diff);

  void setName(const char* name);

  void setSize(int width, int height);
  void size(int& width, int& heigth);

  void setCellAt(int x, int y, int type);
  int cellAt(int x, int y);
};

#endif
