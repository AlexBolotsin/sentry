#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <map>
#include <SDL/SDL.h>
#include <tinyxml.h>
#include <string>
#include "render.hpp"

class TextureLoader {
  std::map<std::string, video::Sprite*> sprites;
  std::string filename;
  int scale;
public:
  TextureLoader();
  ~TextureLoader();

  void setName(const char* filename);
  video::Sprite* getSpriteByName(const std::string& name);
  video::Sprite* getSpriteByName(const char* name);
  video::Sprite* getSpriteByName(const char name);
  void loadTextures();
  void clearCache();

private:
  void cutPiece(SDL_Surface* source, video::Sprite* sprite);
  void rescale(video::Sprite* sprite);
  bool loadImage(SDL_Surface*& image);
  bool loadXML(TiXmlDocument& doc);
};

#endif
