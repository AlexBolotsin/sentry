#include "game.hpp"
#include "fakeloader.hpp"

int main(int argc, char** argv) {
  core::Game* game = FakeLoader().load();
  game->run();
  return game->exitCode();
}
