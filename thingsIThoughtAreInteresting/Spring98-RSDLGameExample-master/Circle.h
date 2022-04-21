#ifndef SAMPLE_PROJECT_CIRCLE_H
#define SAMPLE_PROJECT_CIRCLE_H

#include "rsdl.hpp"

#define GRAVITY 10
#define INITIAL_JUMP_SPEED -50

class Game;

class Circle {
public:
    Circle(Point center, int radius, Game* game);
    void update();
    void draw(Window* win);
    void handle_key_press(char key);
    void handle_key_release(char key);
private:
    bool touches_ground();

    Point center;
    int radius;
    double vx,vy;
    double ay;
    Game* game;
};

#endif
