#include "spaceship.hpp"
using namespace std;
SpaceShip::SpaceShip() : topLeft(Point(rand() % IMAGE_WIDTH, IMAGE_HEIGHT - DISTANCE_FROM_BOTTOM)) {
    cout << "in constructor:\t" << topLeft.x << " " << topLeft.y << endl;
    health = INITIAL_HEALTH;
}


void SpaceShip::set_move(char move) {
    if (move == 'a' || move == 'A' || (int)move == LEFT_ARROW)
        vx = -HORIZONTAL_SPEED;
    else if (move == 'w' || move == 'W'|| (int)move == UP_ARROW) 
        vy = -VERTICAL_SPEED;
    else if (move == 'd' || move == 'D' || (int)move == RIGHT_ARROW) 
        vx = HORIZONTAL_SPEED;
    else if (move == 's' || move == 'S' || (int)move == DOWN_ARROW) 
        vy = VERTICAL_SPEED;
    else if (move == ' ') 
        shoot();
}

void SpaceShip::stop_moving(char move) {
    if (move == 'a' || move == 'A' || (int)move == LEFT_ARROW)
            vx = 0;
    else if (move == 'w' || move == 'W' || (int)move == UP_ARROW) 
            vy = 0;
    else if (move == 'd' || move == 'D' || (int)move == RIGHT_ARROW) 
            vx = 0;
    else if (move == 's' || move == 'S' || (int)move == DOWN_ARROW) 
            vy = 0;
}

void SpaceShip::shoot() {
    play_shooting_sound();
    bullets.push_back(Bullet(get_center(), blockWidth, blockHeight, MY_SPACESHIP));
}

void SpaceShip::update() {
    update_bullets();
    if (is_dead())
        return;
    move();
    draw();
}

void SpaceShip::update_bullets() {
    for (auto& bullet : bullets) 
        bullet.update(win);
}

void SpaceShip::move() { 
    topLeft += Point(vx, vy);
    if (topLeft.x < 0) topLeft.x = 0;
    else if (topLeft.x + blockWidth > win->get_width()) topLeft.x = win->get_width() - blockWidth;
    if (topLeft.y < 0) topLeft.y = 0;
    else if (topLeft.y + blockHeight > win->get_height()) topLeft.y = win->get_height() - blockHeight;
}


void SpaceShip::get_shot() {
    reduce_health();
    play_explosion_sound();
}

void SpaceShip::reduce_health() {
    health--;
    if (health <= 0) 
        die();
}

void SpaceShip::initialise() {
    health = INITIAL_HEALTH;
    topLeft = Point(rand() % win->get_width(), win->get_height() - DISTANCE_FROM_BOTTOM);
    bullets.clear();
}

void SpaceShip::set_window(Window* _win) { win = _win;}
void SpaceShip::play_shooting_sound() { musicPlayerPtr->play_sound_effect(SHOOTING); }
void SpaceShip::play_explosion_sound() { musicPlayerPtr->play_sound_effect(EXPLOSION); }
void SpaceShip::die() { exists = false; }
bool SpaceShip::is_dead() { return exists == false; }
void SpaceShip::set_block_size(int _blockWidth, int _blockHeight) { blockWidth = _blockWidth; blockHeight = _blockHeight;}
void SpaceShip::set_music_player(AudioPlayer* _musicPlayerPtr) { musicPlayerPtr = _musicPlayerPtr; }
void SpaceShip::draw() { win->draw_img(MY_SPACESHIP_PIC, Rectangle(Point(979, 1450), blockWidth, blockHeight)); cout << "in draw:\t" << topLeft.x << " " << topLeft.y << endl; }
Point SpaceShip::get_center() { return topLeft + Point(blockWidth, blockHeight); }
vector<Bullet>* SpaceShip::get_bullets() { return &bullets; }
