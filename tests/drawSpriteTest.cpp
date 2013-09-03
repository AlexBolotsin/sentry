#include <iostream>
#include <unistd.h>
#include "textureloader.hpp"
#include "render.hpp"
#include "font.h"
#include "spriteset.hpp"

int main(int argc, char* argv[]) {
  video::Render render;
  render.init();
  TextureLoader* textureLoader = TextureLoader::getLoader("marry");
  TextureLoader* fontLoader = TextureLoader::getLoader("8bit_font");
  SpriteSet* fontSpriteSet = fontLoader->loadTextureGroup("8bit Font");
  video::FontRender fontRender;
  fontRender.setSpriteSet(fontSpriteSet);
  fontRender.setRender(&render);
  
  SpriteSet* terrainSpriteSet = textureLoader->loadTextureGroup("Terrain");
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 15; j++) {
      render.render(terrainSpriteSet->getSpriteFromGroup("Grass", 0), i*32, j*32);
    }
  }
  fontRender.drawMessage("Hi, George!!", 60, 300, true);
  fontRender.drawMessage("How are you?", 60, 340);

  SpriteSet* alexSpriteSet = textureLoader->loadTextureGroup("Alex");
  SpriteSet* marrySpriteSet = textureLoader->loadTextureGroup("Marry");
  render.render(alexSpriteSet->getSpriteFromGroup("Front", 0), 42, 24);
  render.render(marrySpriteSet->getSpriteFromGroup("Front", 0), 32, 32);
  delete alexSpriteSet;
  delete marrySpriteSet;
  delete terrainSpriteSet;
  delete fontSpriteSet;
  TextureLoader::dropLoaders();
  render.draw();
  usleep(10000*1000);
  return 0;
}
