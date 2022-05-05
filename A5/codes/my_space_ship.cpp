#include "my_space_ship.hpp"

MySpaceShip::MySpaceShip(Window* _win) 
    : SpaceShip(gen_random_point_in_bottom(), _win) {
    stamina = INITIAL_STAMINA;
    vx = vy = 0;
    score = 0;
}

void MySpaceShip::update() {
    if (is_dead())
        return;
    move();
    draw();
}

void MySpaceShip::set_move(char move) {
    if (move == MOVE_SYMBOLS[MOVE_LEFT] || move == MOVE_SYMBOLS[ARROW_LEFT])
        vx = -HORIZONTAL_SPEED;
    else if (move == MOVE_SYMBOLS[MOVE_UP] || move == MOVE_SYMBOLS[ARROW_UP]) 
        vy = -VERTICAL_SPEED;
    else if (move == MOVE_SYMBOLS[MOVE_RIGHT] || move == MOVE_SYMBOLS[ARROW_RIGHT]) 
        vx = HORIZONTAL_SPEED;
    else if (move == MOVE_SYMBOLS[MOVE_DOWN] || move == MOVE_SYMBOLS[ARROW_DOWN]) 
        vy = VERTICAL_SPEED;
}

void MySpaceShip::stop_moving(char move) {
    if (move == MOVE_SYMBOLS[MOVE_LEFT] || move == MOVE_SYMBOLS[ARROW_LEFT])
        vx = 0;
    else if (move == MOVE_SYMBOLS[MOVE_UP] || move == MOVE_SYMBOLS[ARROW_UP]) 
        vy = 0;
    else if (move == MOVE_SYMBOLS[MOVE_RIGHT] || move == MOVE_SYMBOLS[ARROW_RIGHT]) 
        vx = 0;
    else if (move == MOVE_SYMBOLS[MOVE_DOWN] || move == MOVE_SYMBOLS[ARROW_DOWN]) 
        vy = 0;
}

void MySpaceShip::initialise() {
    topLeft = gen_random_point_in_bottom();
    stamina = INITIAL_STAMINA;
    vx = vy = 0;
}

bool MySpaceShip::is_shot_by(const Bullet& bullet) const {
    return bullet.get_type() == ENEMY &&  
        abs(get_center().x - bullet.get_center().x) < MINIMUM_DELTA_X_BULLET &&
        abs(get_center().y - bullet.get_center().y) < MINIMUM_DELTA_Y_BULLET;  
}

void MySpaceShip::draw() { 
    win->draw_img(MY_SPACESHIP_PIC, Rectangle(topLeft, blockWidth, blockHeight));
    for (int i = 0; i < stamina; i++)
        win->draw_img(HEART_PIC,
        Rectangle(INITIAL_LOCATION_OF_HEARTS + Point(i * HEARTS_WIDTH, 0), HEARTS_WIDTH, HEARTS_HEIGHT));
}

void MySpaceShip::has_shot_an_enemy() { score++;}
void MySpaceShip::play_shooting_sound() { musicPlayerPtr->play_sound_effect(SHOOTING); }
Point MySpaceShip::gen_random_point_in_bottom() { return Point(rand() % BACKGROUND_WIDTH, BACKGROUND_HEIGHT - DISTANCE_FROM_BOTTOM); }