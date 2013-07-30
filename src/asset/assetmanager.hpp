#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <list>

class AssetManager {
  typedef std::list<TextureLoader> Loaders;
  Loaders loaders;
public:
  void checkAsset(const char* name);
  void createLoader(const char* name);
  TextureLoader* getLoader(const char* name);
  void dropLoader(const char* name);
};

#endif
