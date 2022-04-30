#ifndef __ENEMIES_HPP__
#define __ENEMIES_HPP__
#include <vector>
#include <set>
#include "moving_enemy.hpp"
#include "audio.hpp"
#include "bullet.hpp"

constexpr int INITIAL_NUM_OF_SHOOTER = 5;
constexpr int FRAME_LIMIT = 100;

class Enemies {
public: 
    Enemies();
    int count_alive();
    void add_member(StationaryEnemy*);
    void update(MySpaceShip&, std::vector<Bullet>&);
    void initialise();
    std::set<int> choose_shooter(int, MySpaceShip&);
    Point get_center_of_index(int);
private:
    std::vector<StationaryEnemy*> list;
    int frameCounter;
};

#endif