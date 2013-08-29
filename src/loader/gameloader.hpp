#ifndef GAME_LOADER_HPP
#define GAME_LOADER_HPP

namespace core {
class Game;
class Scene;
};

class SpriteSet;
class Map;
class TiXmlNode;

class GameLoader {
public:
  core::Game* load();
private:
  void processNode(TiXmlNode* node, core::Game* game);
  core::Scene* loadScene(TiXmlNode* node, bool load_start_screen = false);
  SpriteSet* loadSpriteSet(TiXmlNode* node);
  Map* loadMap(TiXmlNode* node);
};

#endif
