#include "koopa.hpp"

using namespace std;
Koopa::Koopa(Position _position) : position(_position) {
  ground = position.y - BLOCK_SIZE;
};
void Koopa::render(Window *window, int cameraX) {
  if (counter == 20)
    return;

  if (!dead && position.x < cameraX + WIDTH)
    moving = true;
  if (moving)
    run();

  window->draw_img(
      KOOPA_FOLDER +
          (dead ? "dead"
                : (vx > 0 ? "walking-right-" : "walking-left-") +
                      to_string((int)picNum + 1)) +
          ".png",
      Rectangle(-cameraX + position.x, position.y, KOOPA_SIZE, KOOPA_SIZE));
}
void Koopa::shoot(bool right) {
  moving = true;
  vx = 10 * (right ? -1 : 1);
}
Position Koopa::calculateNextMove() {
  int newX, newY;
  int nvy = vy + GRAVITY;
  newY = min(ground - 1, position.y + nvy);
  if (newY == ground - 1) {
    vyShouldReset = true;
    nvy = 0;
    newX = position.x + vx;
  } else
    newX = position.x;
  return Position{newX, newY};
}
void Koopa::run() {
  vy += GRAVITY;
  if (vyShouldReset)
    vy = 0;
  vyShouldReset = false;
  position = calculateNextMove();
  picNum += .25;
  if (picNum >= 2)
    picNum = 1;
}
void Koopa::die() {
  dead = true;
  moving = false;
}
void Koopa::setGround(int g) { ground = g; }
Position Koopa::getPosition() { return position; }
void Koopa::isCrash() { vx = -1 * vx; }
bool Koopa::isMoving() { return moving; }
int Koopa::getY() { return position.y; }
bool Koopa::isAlive() { return !dead; }
