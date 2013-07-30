
int main(int argc, char** argv) {
  Map map;
  map.setSize(100, 100);
  map.setPlayer(&player);
  render->render(&map);

  return 0;
}
