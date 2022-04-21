#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP
#define SCOREBOARD_WIDTH 200
#define SCOREBOARD_X 50
#define SCOREBOARD_HEIGHT 50
#define SCOREBOARD_Y 50
#include "defines.hpp"
class ScoreBoard {
public:
  ScoreBoard();
  void show();
  void addLive();
  void addCoin();
  void update(int live, int coin);
  void decreaseLive();
  void render(Window *window);
  bool isDied();

private:
  int live = 3;
  int coin = 0;
};

#endif
