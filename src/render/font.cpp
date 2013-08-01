#include "font.h"
#include <algorithm>

using namespace video;

FontRender::FontRender() {
}

FontRender::~FontRender() {
}

void FontRender::setFontFile(const char* filename) {
  loader.setName(filename);
  loader.loadTextures();
}

void FontRender::setRender(Render* render) {
  this->render = render;
}

void FontRender::drawMessage(const char* message, int x, int y, bool bg) {
  std::string copy = message;
  drawMessage(copy, x, y, bg);
}

void FontRender::drawMessage(std::string& message, int x, int y, bool bg) {
  std::string copy = message;
  std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
  if (bg) drawBG(copy.size(), x, y);
  for (unsigned int i = 0; i < message.size(); i++) {
    video::Sprite* sprite = loader.getSpriteByName(copy[i]);
    if (!sprite) continue;
    render->render(sprite, x + i*sprite->w, y);
  }
}

void FontRender::drawBG(int size, int x, int y) {
  video::Sprite* sprite = loader.getSpriteByName("top_left_corner");
  render->render(sprite, x - sprite->w, y - sprite->h);
  for (int i = 0; i < size; i++) {
    sprite = loader.getSpriteByName("top_corner");
    render->render(sprite, x + i*sprite->w, y - sprite->h);
  }
  sprite = loader.getSpriteByName("top_right_corner");
  render->render(sprite, x + size*sprite->w, y - sprite->h);

  sprite = loader.getSpriteByName("mid_left_corner");
  render->render(sprite, x - sprite->w, y);
  for (int i = 0; i < size; i++) {
    sprite = loader.getSpriteByName("mid_place");
    render->render(sprite, x + i * sprite->w, y);
  }
  sprite = loader.getSpriteByName("mid_right_corner");
  render->render(sprite, x + size*sprite->w, y);

  sprite = loader.getSpriteByName("low_left_corner");
  render->render(sprite, x - sprite->w, y + sprite->h);
  for (int i = 0; i < size; i++) {
    sprite = loader.getSpriteByName("low_corner");
    render->render(sprite, x + i*sprite->w, y + sprite->h);
  }
  sprite = loader.getSpriteByName("low_right_corner");
  render->render(sprite, x + size*sprite->w, y + sprite->h);
}
