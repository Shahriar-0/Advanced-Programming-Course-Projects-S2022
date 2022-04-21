#include "view.hpp"
using namespace std;
View::View(renderedMap *_map, Mario *_mario, ScoreBoard *_scoreboard) {
  map = _map;
  mario = _mario;
  scoreboard = _scoreboard;
  createWindow();
  bg = new Background(map->width, map->height, window);
}
Window *View::getWindow() { return window; }
void View::reset() { cameraX = 0; }
int View::getCameraX() { return cameraX; }
void View::createWindow() {
  window = new Window(WIDTH, map->height, ".: SuperMario :.");
}
void View::lost() {
  window->clear();
  window->show_text("You lost", Point(270, 200), RED, "assets/FreeSans.ttf",
                    75);
  window->update_screen();
}
void View::win() {
  window->clear();
  window->show_text("You Win", Point(270, 200), GREEN, "assets/FreeSans.ttf",
                    75);
  window->update_screen();
}
void View::nextFrame() {
  window->clear();
  bg->render(cameraX);
  delay(25);
  renderObjects();
  mario->draw(window, cameraX);
  // window->draw_rect(Rectangle(50, 50, 1, 0), RED);
  window->update_screen();
}

void View::moveCameraTo(int newX) {
  if (cameraX >= map->width - 800)
    return;
  if (mario->getX() - cameraX < WIDTH / 2)
    return;
  if (mario->getX() > WIDTH / 2)
    cameraX = newX;
}
void View::renderObjects() {
  moveCameraTo(mario->getX() - WIDTH / 2);
  for (int i = 0; i < map->bonus.size(); i++)
    map->bonus[i].render(window, cameraX);
  for (int i = 0; i < map->blocks.size(); i++)
    map->blocks[i].render(window, cameraX);
  for (int i = 0; i < map->gumbas.size(); i++)
    map->gumbas[i].render(window, cameraX);
  for (int i = 0; i < map->koopas.size(); i++)
    map->koopas[i].render(window, cameraX);
  scoreboard->render(window);
}
