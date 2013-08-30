#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <vector>
#include "render.hpp"
#include "spriteset.hpp"

class Object;

class Map {
  std::string name;
  int width, height;
  int offset_x, offset_y;
  std::vector<int> grid;
  
public:
  Map();
  ~Map();

  /* Updates chunks and objects. Runs animation for both(?).
     I guess so.
   */
  void update(int diff);
  /* Using this stuff you're able to add another object to map.
     Returns false if smth wrong, ie bad coordinates.
  */
  bool addObject(Object* obj, int x, int y);
  /* I hope it will be useful for debugging and stuff.
   */
  void setName(const char* name);
  /* You have to setup size of map in the very beginning of working with this stuff.
   */
  void setSize(int width, int height);
  /* Allows obtain sizes of map.
   */
  void size(int& width, int& heigth);

  /* Well. This is stupid one. It sets type of specific tile in map.
     Probably I can avoid such ugly construction.
   */
  void setCellAt(int x, int y, int type);
  int cellAt(int x, int y);
};

#endif
