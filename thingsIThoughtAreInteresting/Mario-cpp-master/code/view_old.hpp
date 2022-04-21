#ifndef VIEW_HPP
#define VIEW_HPP
#include "defines.hpp"
#include "mario.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define WIDTH 800
#define TITLE_NAME ".: SuperMario :."
#define BLOCK_SIZE 32

using namespace std;
class View {
public:
  View(string fileAddress);
  Window *getWindow() { return window; }
  int getHeight() { return mapHeight; }
  int getWidth() { return mapWidth; }
  int cameraX;
  void drawMap();
  void moveMario(int dir);
  void stopMoving() { mario.stopMoving(); }

private:
  vector<string> map;
  Mario mario;
  Window *window;
  int mapHeight = 0;
  int mapWidth = 0;
  vector<Block> blocks;
  vector<Brick> bricks;
  vector<Question> questions;
  vector<Clay> clays;
  vector<Pipe> pipes;
  vector<Flag> flags;

  void createWindow();
  int getSurface(int x, int y);
  void drawBackground();
  void drawObjects();
  void readMapfile(string address);
};
#endif
