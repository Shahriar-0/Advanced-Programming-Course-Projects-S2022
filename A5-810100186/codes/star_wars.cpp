#include "star_wars.hpp"
using namespace std;

StarWars::StarWars(string filename, Window* _win) : musicPlayer(_win) {
    win = _win;
    // win->draw_img("assets/pictures/background/galaxy.jpeg");
    // AudioPlayer player(win);
    // win->update_screen();
    // player.play_theme();
    // delay(10000);
}