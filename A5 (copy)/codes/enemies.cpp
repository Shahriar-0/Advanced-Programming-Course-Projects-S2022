#include "enemies.hpp"
using namespace std;

int Enemies::count_alive() {
    int alive = 0;
    for (auto& enemy : list) 
        alive += !(enemy->is_dead());
    
    return alive;
}

void Enemies::update(MySpaceShip& mySpaceShip, vector<Bullet>& bullets) {
    for (auto& enemy : list) {
        enemy->update();
        if (enemy->is_dead())
            continue;

        for (auto& bullet : bullets) {
            if (enemy->is_shot_by(bullet)) {
                bullet.extinct();
                enemy->get_shot();
            }
        }
        if (enemy->is_hit_by(mySpaceShip)) {
            enemy->get_shot();
            mySpaceShip.die();
        }
    }   
}

void Enemies::initialise() {
    for (auto& enemy : list) 
        delete enemy;
    
    list.clear();
}
void Enemies::add_member(StationaryEnemy* enemy) { list.push_back(enemy); }