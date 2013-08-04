#include <iostream>
#include "map.hpp"

int main(int argc, char** argv) {
  Map map;
  map.setName("Shitty");
  const int width = 20, height = 20;
  map.setSize(width, height);

  for (int x = 0; x < width; x++)
    for (int y = 0; y < height; y++)
      map.setCellAt(x, y, 1);

  for (int y = 0; y < width; y++) {
    for (int x = 0; x < height; x++) {
      std::cout << map.cellAt(x, y);
    }
    std::cout << std::endl;
  }

  return 0;
}
