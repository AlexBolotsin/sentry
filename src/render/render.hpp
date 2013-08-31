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

  /* Inits sdl and some other stuff.
     Is able to notice an error.
   */
  bool init();
  /* You have to setup window size */
  void setSize(int width, int height);
  /* Allows to draw sprite in a window with custom x and y.
     No protection.
   */
  void render(Sprite* sprite, int x, int y);
  /* Can render map using previous render procedure. It's kinda smart.
     It knows how to draw map with offset and place it in screen.
     It will draw map in center if map is lil than screen.
   */
  void render(Map* map);
  /* Clears screen */
  void clear();
  /* Draw call. Use it carefully. 1 time for frame. */
  void draw();
};

};
#endif
