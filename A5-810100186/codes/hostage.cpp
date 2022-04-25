#include "hostage.hpp"

Hostage::Hostage(Point _topLeft, int _blockWidth, int _blockHeight) : topLeft(_topLeft) {
    blockWidth = _blockWidth;
    blockHeight = _blockHeight;
}

void Hostage::draw(Window* win) {
    win->draw_img(HOSTAGE_PIC, Rectangle(topLeft, blockWidth, blockHeight));
}

Point Hostage::get_center() { return topLeft + Point(blockWidth / 2, blockHeight / 2); }

bool Hostage::is_dead() { return exists == false; }
void Hostage::die() { exists = false; }