#ifndef KOOPA_HPP
#define KOOPA_HPP
#include "defines.hpp"
#define KOOPA_SIZE 32
#define KOOPA_FOLDER "assets/sprites/enemies/koopa_troopa/"
class Koopa {
public:
  Koopa(Position _position);
  void render(Window *window, int cameraX);
  Position calculateNextMove();
  void setGround(int g);
  Position getPosition();
  void isCrash();
  bool isMoving();
  int getY();
  void die();
  bool isAlive();
  void shoot(bool right);

private:
  Position position;
  bool moving = false;
  int ground;
  float picNum = 0.25;
  int vx = -2, vy = 0;
  bool vyShouldReset = false;
  bool dead = false;
  int counter = 0;
  void run();
};

#endif
