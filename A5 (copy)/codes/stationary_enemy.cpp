#include "stationary_enemy.hpp"

StationaryEnemy::StationaryEnemy(Point _topLeft, Window* _win, int _blockWidth, int _blockHeight, AudioPlayer* _player)
    : SpaceShip(_topLeft, _win) {
    set_block_size(_blockWidth, _blockHeight);
    set_music_player(_player);
    vx = vy = 0;
    stamina = 1; //cause the enemies have only one life yet
}

void StationaryEnemy::update() {
    if (is_dead())
        return;
    draw();
}

bool StationaryEnemy::is_shot_by(const Bullet& bullet) const {
    return bullet.get_type() == MY_SPACESHIP &&  
        abs(get_center().x - bullet.get_center().x) < MINIMUM_DELTA_X_BULLET &&
        abs(get_center().y - bullet.get_center().y) < MINIMUM_DELTA_Y_BULLET;  
}

bool StationaryEnemy::is_hit_by(const MySpaceShip& ship) const {
    return abs(get_center().x - ship.get_center().x) < MINIMUM_DELTA_X_SHIPS &&
           abs(get_center().y - ship.get_center().y) < MINIMUM_DELTA_Y_SHIPS;
}

void StationaryEnemy::draw() { win->draw_img(STATIONARY_ENEMY_PIC, Rectangle(topLeft, blockWidth, blockHeight)); }