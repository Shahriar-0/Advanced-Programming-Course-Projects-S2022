#include "../manager/game_manager.hpp"

Player::Player(int _id, int _strength, int _agility, int _intelligence, std::string main_ability)
    : id(_id), strength(_strength), agility(_agility), intelligence(_intelligence), win(0) {

    if (main_ability == AGILE_KEYWORD)
        main_trait = &agility;
    else if (main_ability == STRONG_KEYWORD)
        main_trait = &strength;
    else if (main_ability == INTELLIGENT_KEYWORD)
        main_trait = &intelligence;
}