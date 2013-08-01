#include "render.hpp"
#include "map.hpp"
#include "log.hpp"

using namespace video;

Render::Render() {
}

Render::~Render() {
  SDL_FreeSurface(screen);
  SDL_Quit();
}

bool Render::init() {
    if (SDL_Init(SDL_INIT_VIDEO))
      return false;

    setSize(640, 480);
    screen = SDL_SetVideoMode(width, height, 32, SDL_DOUBLEBUF);
    if (!screen) return false;
    SDL_SetColorKey(screen, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 255, 0, 255));
    return true;
}

void Render::setSize(int width, int height) {
  this->width = width;
  this->height = height;
}

void Render::render(Sprite* sprite, int x, int y) {
  if (!sprite) {
    Log::error("Empty sprite");
    return;
  }
  //SDL_LockSurface(screen);
  SDL_Rect sprite_rect = {0, 0, sprite->w, sprite->h};
  SDL_Rect screen_rect = {x, y, sprite->w, sprite->h};
  SDL_BlitSurface(sprite->image, &sprite_rect, screen, &screen_rect);
  //SDL_UnlockSurface(screen);
}

void Render::render(Map* map) {
  int map_w, map_h;
  int offset_x, offset_y;
  bool stop = false;
  map->size(map_w, map_h);
  int size = map->tileSize();
  map->offset(offset_x, offset_y);
  
  int ox = offset_x/size, oy = offset_y/size;
  int tmp_x = offset_x%size, tmp_y = offset_y%size;
  int ex = width/size+1 < map_w ? width/size+1 : map_w, 
      ey = height/size+1 < map_h ? height/size+1 : map_h;

  for (int i = 0; i < ex; i++) {
    for (int j = 0; j < ey; j++) {
      Sprite* sprite = map->cellAt(ox+i, oy+j);
      if (!sprite) {
	LOG_MSG("Empty sprite from " << ox+i << ":" << oy+i);
      } else {
	render(sprite, sprite->w * i - tmp_x, sprite->h * j - tmp_y);
      }
      for (Sprite* object : map->spritesAt(ox+i, oy+j))
	render(object, object->w * i - tmp_x, object->h * j - tmp_y);
    }
  }
}

void Render::draw() {
    SDL_LockSurface(screen);
    SDL_Flip(screen);
    SDL_UnlockSurface(screen);
}
