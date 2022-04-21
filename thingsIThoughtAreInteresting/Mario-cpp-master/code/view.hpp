#ifndef VIEW_HPP
#define VIEW_HPP
#include "background.hpp"
#include "block.hpp"
#include "defines.hpp"
#include "gumba.hpp"
#include "koopa.hpp"
#include "map_reader.hpp"
#include "mario.hpp"
#include "scoreboard.hpp"

#include <string>
#include <vector>
class View {
public:
  View(renderedMap *_map, Mario *_mario, ScoreBoard *_scoreboard);
  void nextFrame();
  Window *getWindow();
  void moveCameraTo(int newX);
  int getCameraX();
  void reset();
  void win();
  void lost();

private:
  int cameraX = 0;
  ScoreBoard *scoreboard;
  Window *window;
  renderedMap *map;
  void createWindow();
  void renderObjects();
  Background *bg;
  Mario *mario;
};

#endif
