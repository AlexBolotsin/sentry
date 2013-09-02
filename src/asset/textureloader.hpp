#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <map>
#include <vector>
#include <SDL/SDL.h>
#include <tinyxml.h>
#include <string>
#include "render.hpp"

class TextureLoader {
  static std::map<std::string, TextureLoader*> loaders;
  std::map<std::string, std::vector<video::Sprite*>> sprites;
  std::string filename;
  int scale;
public:
  static TextureLoader* getLoader(std::string loader);
  ~TextureLoader();

  void setName(const char* filename);
  video::Sprite* getSpriteFromGroup(const std::string& name, int ingroupNum);
  video::Sprite* getSpriteFromGroup(const char* name, int ingroupNum);
  video::Sprite* getLetter(const char name);
  void loadTextureGroup(std::string groupName);
  void clearCache();

private:
  TextureLoader();

  void cutPiece(SDL_Surface* source, video::Sprite* sprite);
  void rescale(video::Sprite* sprite);
  bool loadImage(SDL_Surface*& image);
  bool loadXML(TiXmlDocument& doc);
};

#endif
