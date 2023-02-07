#include "player.hpp"

Player::Player(int _id, int _strength, int _agility, int _intelligence, std::string main_ability)
    : id(_id), strength(_strength), agility(_agility), intelligence(_intelligence), win(0) {

    if (main_ability == AGILE_KEYWORD)
        main_trait = &agility;
    else if (main_ability == STRONG_KEYWORD)
        main_trait = &strength;
    else if (main_ability == INTELLIGENT_KEYWORD)
        main_trait = &intelligence;
}

int Player::get_win() { return win; }

int Player::calc_skill() {
    return strength + agility + intelligence + (*main_trait);
}

void Player::update_stats() {
    (*main_trait)++;
    win++;
}

double Player::calc_kabab_power() {
    return intelligence + pow(agility, 2);
}

double Player::calc_chess_power() {
    return intelligence;
}

double Player::calc_wrestle_power() {
    return intelligence + pow(strength, 2) + 2 * agility; 
}

double Player::calc_arm_wrestle_power() {
    return strength;
}

