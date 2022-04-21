#include "scoreboard.hpp"
using namespace std;
ScoreBoard::ScoreBoard() {}
void ScoreBoard::show() {}
void ScoreBoard::update(int _live, int _coin) {
  live = _live;
  coin = _coin;
}
void ScoreBoard::addLive() { live++; }
void ScoreBoard::addCoin() { coin++; }
void ScoreBoard::decreaseLive() { live--; }
bool ScoreBoard::isDied() { return live < 0; }
void ScoreBoard::render(Window *window) {
  window->fill_rect(Rectangle(SCOREBOARD_X + 2, SCOREBOARD_Y + 2,
                              SCOREBOARD_WIDTH, SCOREBOARD_HEIGHT),
                    RGB(80, 80, 80));

  window->fill_rect(Rectangle(SCOREBOARD_X, SCOREBOARD_Y, SCOREBOARD_WIDTH,
                              SCOREBOARD_HEIGHT),
                    RGB(190, 190, 250));
  window->show_text("Coin", Point(SCOREBOARD_X + 20, SCOREBOARD_Y + 5), BLACK,
                    "assets/FreeSans.ttf", 15);
  window->show_text(to_string(coin),
                    Point(SCOREBOARD_X + 30, SCOREBOARD_Y + 30), BLACK,
                    "assets/FreeSans.ttf", 15);

  window->show_text("Live", Point(SCOREBOARD_X + 120, SCOREBOARD_Y + 5), BLACK,
                    "assets/FreeSans.ttf", 15);
  window->show_text(to_string(live),
                    Point(SCOREBOARD_X + 130, SCOREBOARD_Y + 30), BLACK,
                    "assets/FreeSans.ttf", 15);
}
