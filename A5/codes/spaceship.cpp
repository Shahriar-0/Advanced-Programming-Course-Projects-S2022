#include "spaceship.hpp"

SpaceShip::SpaceShip(Window* _win, AudioPlayer* _musicPlayerptr, int _blockWidth, int _blockHeight) 
    : center(Point(rand() % win->get_width(), win->get_height() - _blockHeight)) {
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
    musicPlayerptr = _musicPlayerptr;
    win = _win;
    health = INITIAL_HEALTH;
}

