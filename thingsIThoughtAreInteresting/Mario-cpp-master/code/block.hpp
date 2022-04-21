#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "../src/rsdl.hpp"
#include "audio.hpp"
#include "bonus.hpp"
#include "defines.hpp"
#define NO_ACTION 0
#define BREAK 1
#define MOVED_UP 2
#define OPENED 3
#define PIC_SPEED 11
using namespace std;
class Block {
public:
  Block(){};
  Block(Position _position, TYPE _type, int bonus_id);
  Block(Position _position, TYPE _type, bool _breakable = false);
  void breakMe();
  TYPE getType() { return type; }
  void render(Window *window, int cameraX);
  bool isIn(Position pos);
  bool Xin(int x);
  bool Yin(int y);
  Position getPosition();
  int open(bool shouldBreak = false);
  int getBonusId();
  bool isBroken();

private:
  bool breakable = false;
  TYPE type;
  bool haveBonus = false;
  int bonusId = -1;
  bool broken = false;
  Position position;
  bool opened = false;
  int picChanger = 0;
  int vy = 0;
};

#endif
