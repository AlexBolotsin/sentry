#ifndef FAKE_LOADER_HPP
#define FAKE_LOADER_HPP

#include "scene.hpp"
#include "game.hpp"

class SpriteSet;
class Map;

class FakeLoader {
public:
  core::Game* load();
};

#endif
