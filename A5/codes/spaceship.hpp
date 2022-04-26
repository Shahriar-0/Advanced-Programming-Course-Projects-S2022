#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include "bullet.hpp"
#include "audio.hpp"
#include <vector>
#define MY_SPACESHIP_PIC "./assets/pictures/spaceships/my_spaceship.png"
#define INITIAL_HEALTH 3
constexpr int HORIZONTAL_SPEED = 8; 
constexpr int VERTICAL_SPEED = 8; 

class SpaceShip {
public:
    SpaceShip(Window*);
    std::vector<Bullet>* get_bullets();
    void set_music_player(AudioPlayer*);
    void set_window_size(int, int);
    void set_move(char);
    void update();
    void update_bullets();
    void stop_moving(char);
    void move();
    void shoot();
    void check_for_collding_with_ships();
    bool is_dead();
    void die();
    void draw();
    void play_shooting_sound();
    void play_explosion_sound();
    void get_shot();
    Point get_center();
    void reduce_health();
private:
    Window* win;
    AudioPlayer* musicPlayerPtr;
    Point topLeft;
    std::vector<Bullet> bullets;
    int vy, vx;
    bool exists;
    int blockWidth, blockHeight;
    int health;
};

#endif