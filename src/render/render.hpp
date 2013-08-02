#ifndef __RENDER_HPP__
#define __RENDER_HPP__

#include <SDL/SDL.h>

class Map;

namespace video {

struct Sprite {
  int x, y, w, h;
  SDL_Surface* image;
};

class Render {
  int width, height;
  SDL_Surface* screen;
public:
  Render();
  ~Render();

  bool init();
  void setSize(int width, int height);
  void render(Sprite* sprite, int x, int y);
  void render(Map* map);
  void clear();
  void draw();
};

};
#endif
