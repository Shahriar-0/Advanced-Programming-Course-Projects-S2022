#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include "bullet.hpp"
#include "audio.hpp"
#include <vector>
#define MY_SPACESHIP_PIC "./assets/pictures/spaceships/my_spaceship.png"
#define INITIAL_HEALTH 3

class SpaceShip {
public:
    SpaceShip(Window*);
    SpaceShip() : center(Point(0, 0)) {};
    void set_music_player(AudioPlayer*);
    void set_window_size(int, int);
    void move(char);
    void stop_moving(char);
    void shoot();
    void check_for_collding_with_ships();
    bool is_dead();
    void die();
    void draw();
    void play_shooting_sound();
    void play_explosion_sound();
    void get_shot();
private:
    Window* win;
    AudioPlayer* musicPlayerPtr;
    Point center;
    std::vector<Bullet> myBullets;
    int vy, vx;
    bool exists;
    int blockWidth, blockHeight;
    int health;
};

#endif