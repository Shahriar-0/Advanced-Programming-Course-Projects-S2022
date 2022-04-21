#include "bonus.hpp"
using namespace std;
Bonus::Bonus(Position pos, char bonusType, int id) : _id(id), position(pos) {
  if (bonusType == '?')
    type = COIN;
  else if (bonusType == 'm')
    type = RED_MUSH;
  else
    type = H_MUSH;
  ground = pos.y - BLOCK_SIZE;
}
void Bonus::appear() { visible = true; }
void Bonus::disappear() { visible = false; }
Position Bonus::calculateNextMove() {
  int newX, newY;
  vy += GRAVITY;
  newY = min(ground - 1, position.y + vy);
  if (position.y == newY) {
    vy = 0;
    newX = position.x + vx;
  } else
    newX = position.x;

  return Position{newX, newY};
}
void Bonus::run() {
  position = calculateNextMove();
  moving = true;
}
void Bonus::goUp() {
  if (counter < BLOCK_SIZE)
    position.y -= 2;
  else {
    position.y += 1;
    ready = true;
  }
  counter++;
}
void Bonus::render(Window *window, int cameraX) {

  if (!visible)
    return;
  if (counter < BLOCK_SIZE * 2) {
    goUp();
  } else if (type == COIN)
    disappear();
  else {
    run();
  }
  window->draw_img(
      OBJECTS_PIC_ADDRESS[type],
      Rectangle(-cameraX + position.x, position.y, BLOCK_SIZE, BLOCK_SIZE));
}
TYPE Bonus::getType() { return type; }
bool Bonus::isVisible() { return visible; }
bool Bonus::isMoving() { return moving; }
void Bonus::isCrash() { vx = -vx; }
bool Bonus::isReady() { return ready; };
Position Bonus::getPosition() { return position; }
void Bonus::setGround(int g) { ground = g; }
