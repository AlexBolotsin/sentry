#include "gameloader.hpp"
#include "game.hpp"
#include "log.hpp"
#include "map.hpp"
#include "scene.hpp"
#include "object.hpp"
#include "textureloader.hpp"
#include <tinyxml.h>

using application::Game;
using application::Scene;

Game* GameLoader::load() {
  TiXmlDocument doc("game.xml");
  doc.LoadFile();
  TiXmlHandle handle(&doc);
  /*if (!result) {
    Log::error("Can't open game.xml");
    return NULL;
    }*/

  TiXmlElement* element = handle.FirstChildElement().Element();
  if (!element) {
    Log::error("No such element");
    return NULL;
  }

  TiXmlNode* node = element->FirstChildElement("start_screen");
  if (!node) {
    Log::error("Can't find start_screen element");
    return NULL;
  }

  Scene* start_scene = loadScene(node, true);

  Game* game = new Game();
  game->addScene(start_scene);

  /*  node = element->FirstChildElement();
  while (node && node->Type() == TiXmlNode::TINYXML_ELEMENT) {
    LOG_MSG("Current node " << node->Value());
    processNode(node, game);
    node = node->NextSibling();
    }*/

  return game;
}

void GameLoader::processNode(TiXmlNode* node, Game* game) {
  if (node->ValueStr() == "start_screen") {
    Map* map = loadMap(node);
  }
}

Scene* GameLoader::loadScene(TiXmlNode* node, bool load_start_screen) {
  TiXmlElement* element = node->ToElement();
  Scene* scene = new Scene();
  const char* name = element->Attribute("name");
  //scene->setName(name);
  int walkable = 0;
  element->QueryIntAttribute("walkable", &walkable);
  // TODO create input nadler that sets the map offset
  element = node->FirstChildElement();
  while (element) {
    std::string ename = element->Value();
    if (ename == "background") {
      LOG_MSG(ename);
    } else if (ename == "object") {
      Object* obj = new Object();
      obj->setName(element->Attribute("name"));
      //obj->setSpriteSet();
      int x, y;
      element->QueryIntAttribute("pos_x", &x);
      element->QueryIntAttribute("pos_y", &y);
      //scene->getMap()->addObject(obj, x, y);
      LOG_MSG(ename);
    } else if (ename == "tile_map") {
      LOG_MSG("Loading map");
      Map* map = new Map();
      map->setName(element->Attribute("name"));
      int width, height;
      element->QueryIntAttribute("width", &width);
      element->QueryIntAttribute("height", &height);
      map->setSize(width, height);
      TextureLoader* loader = new TextureLoader();
      loader->setName(element->Attribute("sprite_set"));
      SpriteSet* set = new SpriteSet();
      set->setName(element->Attribute("sprite_set"));
      set->setLoader(loader);
      set->setDefault(element->Attribute("default_sprite"));
      map->setSpriteSet(set);
      scene->setMap(map);
    } else if (ename == "exit") {
      LOG_MSG(ename);
    } else if (ename == "next_screen") {
      LOG_MSG(ename);
    } else {
      LOG_MSG("Wrong item name for scene node " << ename);
    }
    element = element->NextSiblingElement();
  }
  return scene;
}

SpriteSet* GameLoader::loadSpriteSet(TiXmlNode* node) {
  return NULL;
}

Map* GameLoader::loadMap(TiXmlNode* node) {
  Map* map = new Map();
  return NULL;
}
