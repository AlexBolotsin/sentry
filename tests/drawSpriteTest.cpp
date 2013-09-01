#include <iostream>
#include <unistd.h>
#include "textureloader.hpp"
#include "render.hpp"
#include "font.h"

int main(int argc, char* argv[]) {
  video::Render render;
  render.init();
  /*TextureLoader loader;
  loader.setName("marry");
  video::FontRender fontrender;
  fontrender.setFontFile("8bit_font");
  fontrender.setRender(&render);
  loader.loadTextures();
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 15; j++) {
      render.render(loader.getSpriteByName("Grass"), i*32, j*32);
    }
  }
  fontrender.drawMessage("Hi, George!!", 60, 300, true);
  fontrender.drawMessage("How are you?", 60, 340);

  render.render(loader.getSpriteByName("Alex"), 42, 24);
  render.render(loader.getSpriteByName("Marry"), 32, 32);
  render.draw();
  usleep(10000*1000);*/
  return 0;
}
