#include "gameloader.hpp"
#include "game.hpp"
#include <iostream>

int main(int argc, char** argv) {
  GameLoader loader;
  application::Game* game = loader.load();
  game->run();
  return 0;
}
