#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <map>
#include <SDL/SDL.h>
#include <tinyxml.h>
#include <string>
#include "render.hpp"
#include "spriteset.hpp"

class TextureLoader {
  static std::map<std::string, TextureLoader*> loaders;
  std::string filename;
  int scale;
public:
  static TextureLoader* getLoader(std::string loader);
  static void dropLoaders();
  ~TextureLoader();

  void setName(const char* filename);
  SpriteSet* loadTextureGroup(std::string groupName);

private:
  TextureLoader();

  void cutPiece(SDL_Surface* source, video::Sprite* sprite);
  void rescale(video::Sprite* sprite);
  bool loadImage(SDL_Surface*& image);
  bool loadXML(TiXmlDocument& doc);
};

#endif
