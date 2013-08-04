#include "scene.hpp"
#include "map.hpp"
#include "iostream"
#include "object.hpp"
#include "spriteset.hpp"
#include "textureloader.hpp"
#include <unistd.h>

int main(int argc, char** argv) {
  video::Render render; // FUCK!
  render.init();
  TextureLoader loader;
  loader.setName("marry");
  Map map;
  map.setSize(100, 100);
  SpriteSet set;
  set.setLoader(&loader);
  set.setDefault("Grass");
  Object obj;
  obj.setSpriteSet(&set);
  application::Scene scene1;
  application::Scene scene2;
  application::Scene scene3;

  scene1.setMap(&map);
  bool result = scene1.load();
  std::cout << result << std::endl;
  scene1.render(&render);
  render.draw();
  usleep(10000*1000);
  scene1.unload();

  scene2.setMap(&map);
  result = scene2.load();
  std::cout << result << std::endl;
  scene2.unload();

  scene3.setMap(&map);
  result = scene3.load();
  std::cout << result << std::endl;
  scene3.unload();
}
