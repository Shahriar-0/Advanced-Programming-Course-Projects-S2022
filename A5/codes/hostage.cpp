#include "hostage.hpp"

Hostage::Hostage() : topLeft(0, 0) {}
void Hostage::set_top_left(Point _topLeft) { topLeft = _topLeft; }
void Hostage::draw(Window* win) { win->draw_img(HOSTAGE_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }
Point Hostage::get_center() { return topLeft + Point(blockWidth / 2, blockHeight / 2); }
bool Hostage::is_dead() { return exists == false; }
void Hostage::die() { exists = false; }