#include "enemies.hpp"
using namespace std;

Enemies::Enemies() { frameCounter = 0; }

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

set<int> Enemies::choose_shooter(int numOfShooters, MySpaceShip& mySpaceShip) {
    //cause each level num of shooter should be more
    //note: cause I'm tired I don't feel up to fix this 
    //but you should be aware that if you have more than 
    //5 levels you should change this function or change
    //initial num of shooters
    int numOfNotShooters = count_alive() - numOfShooters;
    set<int> result;
    // if (frameCounter != 0) {
    //     frameCounter--;
    //     return result; //not time for shooting
    // }

    // frameCounter = rand() % FRAME_LIMIT;
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->is_dead())
            continue;

        if (numOfNotShooters > 0 && list[i]->is_in_near_column_of(mySpaceShip)) {
            //this is just to avoid repetition 
            //basically for every enemy near the ship there's a 30 percent chance to shoot
            //todo: this one has the potential to be way better
            if (rand() % 10 < 3)
                result.insert(i);
            else   
            numOfNotShooters--;
        }
        
        else 
            result.insert(i);
    }
    return result;
}

void Enemies::initialise() {
    for (auto& enemy : list) 
        delete enemy;
    
    list.clear();
}

Point Enemies::get_center_of_index(int i) { return list[i]->get_center(); }
void Enemies::add_member(StationaryEnemy* enemy) { list.push_back(enemy); }