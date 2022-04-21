#ifndef CAMERA_H
#define CAMERA_H

#include "rsdl.hpp"
#include "string"

#define BACKGROUND "assets/background_image.png" 
#define BACKGROUND_HEIGHT 1000 
#define BACKGROUND_WIDTH 2000 
#define FONT "FreeSans.ttf"
#define YOU_WIN "YOU WIN"
#define YOU_LOSE "YOU LOSE"
#define END_X 300
#define END_Y 50

const Point END_POINT(300, 50);

class Camera {
public:
    Camera(int w, int h, std::string name);
    void setBackground();
    Window* getWindow();
    int getWidth();
    int getHeight();
    void updateOffsets(int marioX, int marioVx);
    void clearScreen();
    void updateScreen();
    int getWinOffset();
    int getBackgroundOffset();
    void lose();
    void won();
    void resetOffset();

private:
    Window win;
    int winOffset;
    int backgroundOffset;

};

#endif