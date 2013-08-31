#include "map.hpp"
#include "log.hpp"

Map::Map() : name(""), width(0), height(0) {
  LOG_MSG("Creating map");
}

Map::~Map() {
  LOG_MSG("Destoroing map;");
}

void Map::update(int diff) {
}

void Map::setName(const char* name) {
  this->name = name;
}

bool Map::addObject(Object* obj, int x, int y) {
  return false;
}

void Map::setSize(int width, int height) {
  LOG_MSG("Resize map to " << width << "x" << height);
  this->width = width;
  this->height = height;
  grid.resize(width*height);
}

void Map::size(int& width, int& height) {
  width = this->width;
  height = this->height;
}

void Map::setCellAt(int x, int y, int type) {
  grid[x+y*width] = type;
}

int Map::cellAt(int x, int y) {
  return grid[x + y*width];
}

