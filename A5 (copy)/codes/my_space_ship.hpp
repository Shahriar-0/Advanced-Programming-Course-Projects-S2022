#ifndef __MY_SPACE_SHIP_HPP__
#define __MY_SPACE_SHIP_HPP__
#include "space_ship.hpp"
#include "bullet.hpp"

#define MY_SPACESHIP_PIC "./assets/pictures/spaceships/my_spaceship.png"
constexpr int INITIAL_STAMINA        = 3;
constexpr int HORIZONTAL_SPEED       = 50; 
constexpr int VERTICAL_SPEED         = 50; 
constexpr int DISTANCE_FROM_BOTTOM   = 200;
constexpr int MINIMUM_DELTA_X_BULLET = 60;
constexpr int MINIMUM_DELTA_Y_BULLET = 60;


enum MOVES {
    MOVE_LEFT, 
    ARROW_LEFT, 
    MOVE_UP,
    ARROW_UP,
    MOVE_RIGHT,
    ARROW_RIGHT,
    MOVE_DOWN,
    ARROW_DOWN,
    SHOOT
};

const char MOVE_SYMBOLS[] = {
    'a', 
    'P',
    'w',
    'R',
    'd',
    'O', 
    's',
    'Q', 
    ' '
};

class MySpaceShip : public SpaceShip {
public:
    MySpaceShip(Window*);
    void set_move(char);
    void stop_moving(char);
    virtual void draw();
    virtual void update(); 
    void initialise();
    bool is_shot_by(const Bullet&) const;
    void play_shooting_sound();
private:
    Point gen_random_point_in_bottom();
};

#endif