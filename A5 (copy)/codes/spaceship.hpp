#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include "rsdl.hpp"


class SpaceShip {
public:
    SpaceShip(Point, Window*);
    void set_music_player(AudioPlayer*);
protected:
    Point center;
    Window* win;
    AudioPlayer* musicPlayer;
};

#endif