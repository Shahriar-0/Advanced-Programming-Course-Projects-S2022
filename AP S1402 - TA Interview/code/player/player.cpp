#include "player.hpp"

using namespace std;

Player::Player(int _id, int _strength, int _agility, int _intelligence, std::string main_ability)
    : id(_id), strength(_strength), agility(_agility), intelligence(_intelligence), win(0) {
    const std::string STRONG_KEYWORD = "strong";
    const std::string AGILE_KEYWORD = "agile";
    const std::string INTELLIGENT_KEYWORD = "intelligent";

    if (main_ability == AGILE_KEYWORD)
        main_trait = &agility;
    else if (main_ability == STRONG_KEYWORD)
        main_trait = &strength;
    else if (main_ability == INTELLIGENT_KEYWORD)
        main_trait = &intelligence;
}

void Player::update_stats_after_win() {
    (*main_trait)++;
    win++;
}

ostream& operator<<(ostream& out, const Player& player) {
    out << player.id;
    return out;
}

void Player::update_stats_after_lose() { win = 0; }

int Player::calc_skill() { return strength + agility + intelligence + (*main_trait); }

double Player::calc_kabab_power() { return intelligence + pow(agility, 2); }

double Player::calc_chess_power() { return intelligence; }

double Player::calc_wrestle_power() { return intelligence + pow(strength, 2) + 2 * agility; }

double Player::calc_arm_wrestle_power() { return strength; }

int Player::get_win() { return win; }