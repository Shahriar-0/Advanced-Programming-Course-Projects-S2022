#include "background.hpp"

Background::Background(int _mapWidth, int _mapHeight, Window *win) {
  mapWidth = _mapWidth;
  mapHeight = _mapHeight;
  window = win;
}
void Background::render(int cameraX) {
  for (int i = 0; i < mapWidth / mapHeight; i++)
    window->draw_img(BG_ADDRESS, Rectangle(-cameraX / 2 + i * mapHeight * 2, 0,
                                           mapHeight * 2, mapHeight));
}
