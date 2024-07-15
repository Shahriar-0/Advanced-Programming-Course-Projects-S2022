#include "hostage.hpp"

Hostage::Hostage(Point _topLeft, Window* _win, int _blockWidth, int _blockHeight, AudioPlayer* _player)
    : SpaceShip(_topLeft, _win) {
    set_block_size(_blockWidth, _blockHeight);
    set_music_player(_player);
    vx = vy = 0;
    stamina = 1;
}
void Hostage::update() {
    if (is_dead())
        return;
    draw();
}

bool Hostage::is_hit_by(const MySpaceShip& ship) const {
    return abs(get_center().x - ship.get_center().x) < MINIMUM_DELTA_X_SHIPS &&
           abs(get_center().y - ship.get_center().y) < MINIMUM_DELTA_Y_SHIPS;
}

bool Hostage::is_shot_by(const Bullet& bullet) const {
    return bullet.get_type() == MY_SPACESHIP &&  
        abs(get_center().x - bullet.get_center().x) < MINIMUM_DELTA_X_BULLET &&
        abs(get_center().y - bullet.get_center().y) < MINIMUM_DELTA_Y_BULLET;  
}

void Hostage::draw() { win->draw_img(HOSTAGE_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }