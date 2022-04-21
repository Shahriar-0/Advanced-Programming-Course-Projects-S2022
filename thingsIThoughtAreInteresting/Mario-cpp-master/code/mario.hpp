#ifndef MARIO_HPP
#define MARIO_HPP
#include "../src/rsdl.hpp"
#include "defines.hpp"
#define MARIO_SMALL_WIDTH 24
#define MARIO_SMALL_HEIGHT 32
#define MARIO_FOLDER "assets/sprites/mario/"
#define MARIO_REACT -20
#define VX 7
#define VY -25
using namespace std;

class Mario {
public:
  Mario(Position pos);
  Mario();
  void draw(Window *window, int cameraX);
  int getY();
  int getX();
  void setY(int _y);
  void setX(int _x);
  Position getPosition();
  int getVx();
  int getVy();
  void setVy(int _y);
  void setPosition(Position pos);
  void move(int dir);
  void stopMoving();
  void setGround(int g);
  bool jump();
  bool stopJump();
  void crashedTo(int x, int y);
  void getBig();
  bool isBig();
  int getWidth();
  int getHeight();
  Position nextPosition();
  void moveBottom();
  Position getLastPosition();
  int getLastVy();
  void getSmall();
  void die(bool forceDie = false);
  bool isDieHard();
  Rect getRect();
  void toggleDead();
  void goDown();

private:
  bool dead = false;
  bool dieHard = false;
  int direction = 1;
  bool isSmall = true;
  int initialX, initialY;
  int x, y;
  int oldX, oldY;
  int oldVx, oldVy;
  int oldGround;
  int vx = 0;
  bool sliding = false;
  int vy = 0;
  int width = MARIO_SMALL_WIDTH;
  int height = MARIO_SMALL_HEIGHT;
  int isWalking = false;
  float picNum = 1;
  int ground = 0;
  int dieHardTimer = 0;
  void moveMario();
};
#endif
