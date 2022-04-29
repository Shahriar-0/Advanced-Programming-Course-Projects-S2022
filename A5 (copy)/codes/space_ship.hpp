#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include "rsdl.hpp"
#include "audio.hpp"

class SpaceShip {
public:
    SpaceShip(Point, Window*);
    void set_music_player(AudioPlayer*);
    void set_block_size(int, int);
    void move();
    void get_shot();
    void play_explosion_sound();
    void reduce_stamina();
    void die();
    bool is_dead() const;
    Point get_center() const;

    virtual void draw() = 0;
    virtual void update() = 0;
protected:
    int vx, vy;
    int blockWidth, blockHeight;
    Point topLeft;
    Window* win;
    AudioPlayer* musicPlayerPtr;
    bool exists;
    int stamina;
};

#endif