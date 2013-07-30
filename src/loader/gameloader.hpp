#ifndef GAME_LOADER_HPP
#define GAME_LOADER_HPP

namespace application {
class Game;
class Scene;
};

class SpriteSet;
class Map;
class TiXmlNode;

class GameLoader {
public:
  application::Game* load();
private:
  void processNode(TiXmlNode* node, application::Game* game);
  application::Scene* loadScene(TiXmlNode* node, bool load_start_screen = false);
  SpriteSet* loadSpriteSet(TiXmlNode* node);
  Map* loadMap(TiXmlNode* node);
};

#endif
