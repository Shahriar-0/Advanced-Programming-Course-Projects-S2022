#ifndef GAME_HPP
#define GAME_HPP
#include "../src/rsdl.hpp"
#include "audio.hpp"
#include "block.hpp"
#include "defines.hpp"
#include "gumba.hpp"
#include "map_reader.hpp"
#include "mario.hpp"
#include "view.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

class Game {
public:
  Game(std::string mapFileAddress);

private:
  renderedMap map;
  Window *window;
  Mario mario;
  string mapFileAddress;
  vector<Block *> bonusBlocks;
  ScoreBoard scoreboard;
  View *view;
  AudioPlayer *audioPlayer;
  bool isWin = false, isLost = false;
  void win();
  void lost();
  void setup();
  void checkWin();
  void die(bool forceDie = false);
  int getGround(Rect rect);
  bool hasConflict(Rect rect);
  bool isConflict(Rect rect1, Rect rect2);
  void coinHandler(Block *b);
  void mushroomHandler();
  void koopaVsGumbaHandler();
  void setGroundToBonuses();
  void gumbaHandler();
  void koopaHandler();
  void setGroundToGumba();
  bool isMarioCrash();
  void handleFall();
  void handleCrashes();
  void handleEvents();
  void hitBlock(Block *b);
  void getHealthMush();
  void getRedMush();
  void setGroundToKoopa();
};
#endif
