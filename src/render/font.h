#ifndef FONT_HPP
#define FONT_HPP

#include <string>
#include "textureloader.hpp"

namespace video {

class FontRender {
  TextureLoader* loader;
  Render* render;
 public:
  FontRender();
  ~FontRender();

  void setFontFile(const char* filename);
  void setRender(Render* render);
  void drawMessage(const char* message, int x, int y, bool bg = false);
  void drawMessage(std::string& message, int x, int y, bool bg = false);
 private:
  void drawBG(int size, int x, int y);
};

};

#endif
