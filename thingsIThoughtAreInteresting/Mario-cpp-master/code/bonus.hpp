#ifndef BONUS_HPP
#define BONUS_HPP

#include "../src/rsdl.hpp"
#include "defines.hpp"
using namespace std;
class Bonus {
public:
  Bonus(Position pos, char bonusType, int id);
  Bonus(){};
  void appear();
  void render(Window *window, int cameraX);
  TYPE getType();
  void disappear();
  bool isVisible();
  bool isMoving();
  Position getPosition();
  void setGround(int g);
  Position calculateNextMove();
  void isCrash();
  void goUp();
  bool isReady();

private:
  int _id;
  Position position;
  int counter = 0;
  bool ready = false;
  bool visible = false;
  TYPE type = BONUS_DEFAULT;
  int vx = 5, vy = 0;
  int ground;
  bool moving = false;
  void run();
};

#endif
