#include "spaceship.hpp"

SpaceShip::SpaceShip(Window* _win)  : center(Point(rand() % win->get_width(), win->get_height() - 50)) {
    //50 is just a rational random number for
    win = _win;
    health = INITIAL_HEALTH;
}

void SpaceShip::set_window_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
