#ifndef __ENEMIES_HPP__
#define __ENEMIES_HPP__
#include <vector>
#include "moving_enemy.hpp"
#include "audio.hpp"
#include "bullet.hpp"

constexpr int INITIAL_NUM_OF_SHOOTER = 5;
constexpr int FRAME_LIMIT            = 100;
constexpr int INITIAL_PERCENTAGE     = 40;
constexpr int INCREASE_PER_LEVEL     = 5;

class Enemies {
public: 
    Enemies() = default;
    int count_alive();
    void add_member(StationaryEnemy*);
    void update(MySpaceShip&, std::vector<Bullet>&);
    void initialise();
    std::vector<int> choose_shooter(int, MySpaceShip&);
    Point get_center_of_enemy_in_index(int);
private:
    std::vector<StationaryEnemy*> list;
    int frameCounter;
};

#endif