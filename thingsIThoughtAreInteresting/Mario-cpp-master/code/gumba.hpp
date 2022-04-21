#ifndef GUMBA_HPP
#define GUMBA_HPP
#include "defines.hpp"
#define GUMBA_SIZE 32
class Gumba {
public:
  Gumba(Position _position);
  void render(Window *window, int cameraX);
  Position calculateNextMove();
  void setGround(int g);
  Position getPosition();
  void isCrash();
  bool isMoving();
  int getY();
  void die();
  bool isAlive();

private:
  Position position;
  bool moving = false;
  int ground;
  float picNum = 0.25;
  int vx = -5, vy = 0;
  bool vyShouldReset = false;
  bool dead = false;
  int counter = 0;
  void run();
};

#endif
