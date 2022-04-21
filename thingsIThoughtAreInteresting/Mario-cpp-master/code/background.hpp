#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#define BG_ADDRESS "assets/background_image.png"
#include "../src/rsdl.hpp"
class Background {
public:
  Background(int _mapWidth, int _mapHeight, Window *win);
  void render(int cameraX);

private:
  int mapWidth, mapHeight;
  Window *window;
};
#endif
