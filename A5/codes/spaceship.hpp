#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__
#include <vector>
#include "bullet.hpp"
#include "audio.hpp"
#define MY_SPACESHIP_PIC "./assets/pictures/spaceships/my_spaceship.png"
constexpr int INITIAL_HEALTH = 3;
constexpr int HORIZONTAL_SPEED = 50; 
constexpr int VERTICAL_SPEED = 50; 
constexpr int DISTANCE_FROM_BOTTOM = 200;

class SpaceShip {
public:
    SpaceShip();
    void set_music_player(AudioPlayer*);
    void set_block_size(int, int);
    void set_move(char);
    void stop_moving(char);
    void update();
    void update_bullets();
    void move();
    void shoot();
    bool is_dead();
    void draw();
    void play_shooting_sound();
    void play_explosion_sound();
    void die();
    void get_shot();
    void initialise();
    void set_window(Window*);
    Point get_center();
    std::vector<Bullet>* get_bullets();
private:
    void reduce_health();
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