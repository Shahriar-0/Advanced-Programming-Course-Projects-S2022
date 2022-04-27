#ifndef __STATIONARY_ENEMY_HPP__
#define __STATIONARY_ENEMY_HPP__
#include <vector>
#include "bullet.hpp"
#include "spaceship.hpp"

#define STATIONARY_ENEMY_PIC "./assets/pictures/spaceships/stationary_enemy.png"
constexpr int FRAME_LIMIT = 150;
constexpr int COLLISION_RANGE = 15;

class StationaryEnemy {
public:
    StationaryEnemy(Point, int, int);
    StationaryEnemy();
    void draw(Window*);
    void update(Window*); 
    void check_for_hitting_spaceship(SpaceShip*);
    bool check_for_getting_hit(SpaceShip*);
    Point get_center();
    void update_bullets(Window*); 
    void check_for_collding_with_ship(SpaceShip*);
    bool is_dead();
    bool are_colliding(Point);
    void play_explosion_sound();
    void shoot();
    void die();
private:
    int blockWidth, blockHeight;
    int frameCounter;
    Point topLeft;
    std::vector<Bullet> bullets;
    bool exists;
};

#endif