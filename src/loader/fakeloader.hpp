#ifndef FAKE_LOADER_HPP
#define FAKE_LOADER_HPP

namespace core {
  class Game;
  class Scene;
};

class SpriteSet;
class Map;

class FakeLoader {
  core::Game* load();
};

#endif
