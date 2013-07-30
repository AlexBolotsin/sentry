#ifndef SCENE_HPP
#define SCENE_HPP

#include "render.hpp"

class Object;
class Map;

namespace application {

class Scene {
  Map* map;
  bool isReady;
public:
  Scene();

  void render(video::Render* render);
  void update(int diff);
  bool load();
  void unload();
  bool ready();
  void setMap(Map* map);
};

};

#endif
