#ifndef SAMPLE_PROJECT_GAME_H
#define SAMPLE_PROJECT_GAME_H

#include "Circle.h"

class Game {
public:
    Game();
    void run();
    int get_ground_y() { return win.get_height(); }
private:
    void process_events();
    void draw_screen();
    void update_objects();

    bool game_running;
    Circle circle;
    Window win;
};

#endif
