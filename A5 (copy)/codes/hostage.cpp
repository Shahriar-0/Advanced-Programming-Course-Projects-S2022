#include "hostage.hpp"

Hostage::Hostage(Point _topLeft, Window* _win)
    : SpaceShip(_topLeft, _win) {
    vx = vy = 0;
    stamina = 1;
}
void Hostage::update() {
    if (is_dead())
        return;
    draw();
}

bool Hostage::is_shot_by(const Bullet& bullet) const {
    return bullet.get_type() == MY_SPACESHIP &&  
        abs(get_center().x - bullet.get_center().x) < MINIMUM_DELTA_X_BULLET &&
        abs(get_center().y - bullet.get_center().y) < MINIMUM_DELTA_Y_BULLET;  
}

void Hostage::draw() { win->draw_img(HOSTAGE_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }