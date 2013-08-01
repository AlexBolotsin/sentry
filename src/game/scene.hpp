#ifndef SCENE_HPP
#define SCENE_HPP

#include "render.hpp"
#include <string>

class Object;
class Map;

namespace application {

class Scene {
  Map* map;
  bool isReady;
  std::string name;
public:
  Scene();

  void render(video::Render* render);
  void setName(const char* name);
  void update(int diff);
  bool load();
  void unload();
  bool ready();
  void setMap(Map* map);
  Map* getMap();
};

};

#endif
