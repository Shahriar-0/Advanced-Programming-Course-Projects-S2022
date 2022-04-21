#include "Circle.h"
#include "Game.h"

Circle::Circle(Point _center, int _radius, Game* _game) : center(_center) {
    radius = _radius;
    vx = vy = 0;
    ay = GRAVITY;
    game = _game;
}

void Circle::update() {
    center.x += vx;
    center.y += vy;
    vy += ay;

    if (touches_ground()) {
        center.y = game->get_ground_y() - radius;
        vy = ay = 0;
    }
}

void Circle::draw(Window* win) {
    win->fill_circle(center, radius, GREEN);
}

void Circle::handle_key_press(char key) {
    switch(key) {
        case 'd':
            vx = 15;
            break;
        case 'a':
            vx = -15;
            break;
        case 'w':
            if (touches_ground()) {
                vy = INITIAL_JUMP_SPEED;
                ay = GRAVITY;
            }
            break;
    }
}

void Circle::handle_key_release(char key) {
    std::cout<<"release called:"<<key<<std::endl;
    switch(key) {
        case 'd':
            if (vx > 0) vx = 0;
            break;
        case 'a':
            if (vx < 0) vx = 0;
            break;
    }
}

bool Circle::touches_ground() {
    return center.y + radius >= game->get_ground_y();
}
