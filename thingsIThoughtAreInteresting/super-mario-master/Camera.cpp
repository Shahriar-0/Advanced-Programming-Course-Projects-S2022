#include "Camera.h"

using namespace std;

Camera::Camera(int w, int h, std::string name): win(w, h, name){
    winOffset = backgroundOffset = 0;
}

void Camera::setBackground() {
    if (backgroundOffset >= BACKGROUND_WIDTH)
        backgroundOffset = 0;
    if (win.get_width() + backgroundOffset >= BACKGROUND_WIDTH) {
        int prevBGWidth = BACKGROUND_WIDTH - backgroundOffset;
        int newBGWidth = win.get_width() - prevBGWidth;
        win.draw_img(BACKGROUND,
            Rectangle(0, 0, prevBGWidth, win.get_height()),
            Rectangle(backgroundOffset, BACKGROUND_HEIGHT - win.get_height(),
            prevBGWidth , win.get_height())
        );
        win.draw_img(BACKGROUND,
            Rectangle(prevBGWidth, 0, newBGWidth, win.get_height()),
            Rectangle(0, BACKGROUND_HEIGHT - win.get_height(),
            newBGWidth, win.get_height())
        );
    }
    else {
        win.draw_img(BACKGROUND, NULL_RECT,
            Rectangle(Point(backgroundOffset, BACKGROUND_HEIGHT - win.get_height()),
            win.get_width(), win.get_height())
        );
    }
}

Window* Camera::getWindow() {
    return &win;
}

int Camera::getWinOffset() {
    return winOffset;
}

int Camera::getBackgroundOffset() {
    return backgroundOffset;
}

int Camera::getWidth() {
    return win.get_width();
}

int Camera::getHeight() {
    return win.get_height();
}

void Camera::updateOffsets(int marioX, int marioVx) {
    if (marioX - winOffset > win.get_width() / 2) {
        if (marioVx > 0) {
            winOffset += marioVx;
            backgroundOffset += marioVx;
        }
    }
}

void Camera::clearScreen() {
    win.clear();
}

void Camera::updateScreen() {
    win.update_screen();
}

void Camera::lose() {
    win.show_text(YOU_LOSE, END_POINT, BLACK, FONT, 70 );
    win.update_screen();
    delay(5000);
}

void Camera::won() {
    win.show_text(YOU_WIN, END_POINT, BLACK, FONT, 70 );
    win.update_screen();
    delay(5000);
}

void Camera::resetOffset() {
    winOffset = backgroundOffset = 0;
}
