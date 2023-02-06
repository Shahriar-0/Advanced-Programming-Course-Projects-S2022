#include "../manager/game_manager.hpp"

GameManager::Player::Player(int _id, int _power, int _speed, int _intelligence, std::string main_ability)
    : id(_id), power(_power), speed(_speed), intelligence(_intelligence), win(0) {

    if (main_ability == AGILE_KEYWORD)
        main_trait = &speed;
    else if (main_ability == STRONG_KEYWORD)
        main_trait = &power;
    else if (main_ability == INTELLIGENT_KEYWORD)
        main_trait = &intelligence;
}