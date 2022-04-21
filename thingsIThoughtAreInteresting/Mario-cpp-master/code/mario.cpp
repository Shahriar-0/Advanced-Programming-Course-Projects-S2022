#include "mario.hpp"
using namespace std;
Mario::Mario(Position pos) {
  initialX = x = pos.x;
  initialY = y = pos.y;

  oldX = x;
  oldY = y;
}
Mario::Mario() {
  x = 0;
  y = 0;
}
Rect Mario::getRect() { return Rect{getPosition(), getWidth(), getHeight()}; }
void Mario::stopMoving() {
  static int counter = 0;
  counter++;
  int tempVx = vx;

  if (sliding && counter % 3 == 0)
    vx += vx > 0 ? -2 : vx < 0 ? +2 : 0;
  if (vx * tempVx < 0)
    vx = 0;
  sliding = true;
  if (vx == 0)
    isWalking = false;
}
void Mario::move(int dir) {
  vx = VX * dir * (y != ground ? 0.75 : 1);
  isWalking = true;
  sliding = false;
  direction = dir;
}
void Mario::moveMario() {
  picNum += .25;
  if (picNum == 4)
    picNum = 1;
  oldX = x;
  x += vx;
  x = max(0, x);
}
void Mario::moveBottom() {
  vy += GRAVITY;
  oldY = y;
  y = y + vy;
  if (y > ground) {
    y = ground;
    vy = 0;
  }
}
void Mario::crashedTo(int _x, int _y) {
  vy = 0;
  x = _x;
  y = _y;
}
bool Mario::jump() {
  if (y != ground)
    return false;
  vy = VY;
  // moveBottom();
  return true;
};
bool Mario::stopJump() {
  if (vy < 0) {
    vy = 0;
    return true;
  }
  return false;
}
void Mario::getBig() {
  isSmall = false;
  width = MARIO_SMALL_WIDTH * 1;
  height = MARIO_SMALL_HEIGHT * 1.5;
}
void Mario::getSmall() {
  isSmall = true;
  width = MARIO_SMALL_WIDTH;
  height = MARIO_SMALL_HEIGHT;
}
void Mario::goDown() { y += 5; }
void Mario::draw(Window *window, int cameraX) {
  dieHardTimer++;
  if (dieHardTimer == 50)
    dieHard = false;

  oldY = y;
  oldX = x;
  oldVx = vx;
  oldVy = vy;
  if (!dead) {
    moveMario();
    if (sliding)
      stopMoving();
    moveBottom();
  }
  if (dieHard && dieHardTimer % 2 == 0)
    return;
  window->draw_img(
      MARIO_FOLDER + string(isSmall ? "normal" : "big") + "/" +
          (dead ? "dead"
                : string(isWalking && y == ground
                             ? "walking-"
                             : y == ground ? "standing-" : "jumping-") +
                      string(direction >= 0 ? "right" : "left") +
                      string(isWalking && y == ground
                                 ? string("-" + to_string((int)picNum))
                                 : "")) +
          ".png",
      Rectangle(-cameraX + x, y, width, height));
}

int Mario::getY() { return y; }
int Mario::getX() { return x; }
void Mario::setY(int _y) { y = _y; }
void Mario::setX(int _x) { x = _x; }
Position Mario::getPosition() { return Position{x, y}; }
int Mario::getVx() { return vx; }
int Mario::getVy() { return vy; }
void Mario::setVy(int _y) { vy = _y; }
void Mario::setPosition(Position pos) {
  y = pos.y;
  x = pos.x;
}
void Mario::setGround(int g) {
  oldGround = ground;
  ground = g;
}
bool Mario::isBig() { return !isSmall; }
int Mario::getWidth() { return width; }
int Mario::getHeight() { return height; }
Position Mario::getLastPosition() { return Position{oldX, oldY}; }
int Mario::getLastVy() { return oldVy; }
void Mario::toggleDead() { dead = !dead; }
void Mario::die(bool forceDie) {
  if (isSmall || forceDie) {
    y = initialY - height;
    vx = 0, vy = 0;
    x = initialX;
    direction = 1;
  }
  getSmall();
  dieHard = true;
  dieHardTimer = 0;
}
bool Mario::isDieHard() { return dieHard; }
