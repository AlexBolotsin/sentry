#ifndef FONT_HPP
#define FONT_HPP

#include <string>
#include "spriteset.hpp"

namespace video {

class FontRender {
  SpriteSet* spriteSet;
  Render* render;
 public:
  FontRender();
  ~FontRender();

  void setSpriteSet(SpriteSet* spriteSet);
  void setRender(Render* render);
  void drawMessage(const char* message, int x, int y, bool bg = false);
  void drawMessage(std::string& message, int x, int y, bool bg = false);
 private:
  void drawBG(int size, int x, int y);
};

};

#endif
