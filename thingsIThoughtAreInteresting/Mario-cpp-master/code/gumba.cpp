#include "gumba.hpp"

using namespace std;
Gumba::Gumba(Position _position) : position(_position) {
  ground = position.y - BLOCK_SIZE;
};
void Gumba::render(Window *window, int cameraX) {
  if (counter == 20)
    return;
  if (dead) {
    counter++;
    picNum = 2;
    position.y += 3;
  } else {
    if (position.x < cameraX + WIDTH)
      moving = true;
    if (moving)
      run();
  }

  window->draw_img(
      OBJECTS_PIC_ADDRESS[GUMBA1 + (int)picNum],
      Rectangle(-cameraX + position.x, position.y, GUMBA_SIZE, GUMBA_SIZE));
}
Position Gumba::calculateNextMove() {
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
void Gumba::run() {
  vy += GRAVITY;
  if (vyShouldReset)
    vy = 0;
  vyShouldReset = false;
  position = calculateNextMove();
  picNum += .25;
  if (picNum >= 2)
    picNum = 0;
}
void Gumba::die() { dead = true; }
void Gumba::setGround(int g) { ground = g; }
Position Gumba::getPosition() { return position; }
void Gumba::isCrash() { vx = -1 * vx; }
bool Gumba::isMoving() { return moving; }
int Gumba::getY() { return position.y; }
bool Gumba::isAlive() { return !dead; }
