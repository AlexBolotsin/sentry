#include "map.hpp"
#include "log.hpp"

Map::Map() : name(""), set(NULL), width(0), height(0),
	     def_sprite(NULL), offset_x(0), offset_y(0) {
  LOG_MSG("Creating map");
}

Map::~Map() {
  LOG_MSG("Destoroing map;");
}

void Map::update(int diff) {
}

bool Map::load() {
  LOG_MSG("Loading scene objects " << objects.size());
  int counter = 0;

  for (Object* obj : objects) {
    if (!obj->load())
      return false;
    else
      counter++;
  }
  LOG_MSG("Loaded " << counter << " objects");

  // TODO delete
  set->load();
  for (Cell& cell : grid) {
    cell.sprite = set->getDefault();
    for (Object* obj : cell.objects)
      obj->load();
    LOG_MSG(std::hex << cell.sprite);
  }
  
  return true;
}

void Map::unload() {
  LOG_MSG("Droping objects " << objects.size());
  for (Object* obj : objects) {
    obj->unload();
  }
}

void Map::addObject(Object* obj, int x, int y) {
  LOG_MSG("Adding object at " << x << ":" << y);
  objects.push_back(obj);
  grid[x + y*width].objects.push_back(obj);
}

void Map::setName(const char* name) {
  this->name = name;
}

void Map::setSpriteSet(SpriteSet* set) {
  this->set = set;
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

void Map::setOffset(int x, int y) {
  offset_x = x;
  offset_y = y;
}

void Map::offset(int& x, int& y) {
  x = offset_x;
  y = offset_y;
}

int Map::tileSize() {
  return set->getDefault()->w;
}

video::Sprite* Map::cellAt(int x, int y) {
  LOG_MSG(x+y*width);
  return grid[x + y*width].sprite;
}

std::list<video::Sprite*> Map::spritesAt(int x, int y) {
  LOG_MSG(x+y*width);
  std::list<video::Sprite*> sprites;
  for (Object* obj : grid[x+y*width].objects) {
    sprites.push_back(obj->getSprite());
  }
  return sprites;
}
