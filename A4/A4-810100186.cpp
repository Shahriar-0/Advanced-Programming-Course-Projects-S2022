#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Gun {
public:
    Gun (int _price, int _damage, int _prizeForKilling) {
        price = _price;
        damage = _damage;
        prizeForKilling = _prizeForKilling;
    }
    int price;
    int damage;
    int prizeForKilling;
};

//some predefined variables
const Gun HEAVY(3000, 45, 100);
const Gun PISTOL(400, 20, 200);
const Gun KNIFE(0, 35, 500);
#define MAX_MONEY 10000
#define WIN_PRIZE 2700
#define LOSE_PRIZE 2400

enum PlayerMode {AFK, ATK};
enum GameMode {START_MENU, DURING_GAME, FINISHED};
enum Player_status {DEAD, ALIVE};

class Player {
public:
    Player (string _username, string _teamname) {
        username = _username;
        teamname = _teamname;
    }
    int get_money() { return money; }
    int get_health() { return health; }
    void add_money(int);
    string get_username() { return username; }
    string get_teamname() { return teamname; }
    void go_AFK() { mode = AFK; }
    void go_ATK() { mode = ATK; }
    void shoot(Player);
    void buy(Gun);
private:    
    string teamname;
    string username;
    vector<Gun> listOfGuns;
    int money;
    int health;
    PlayerMode mode;
    Player_status
};

void Player::add_money(int income) {
    money += income;
    if (money > MAX_MONEY)
        money = MAX_MONEY;
}

void Player::shoot(Player attacked) {
    //TODO
}

void Player::buy(Gun gun) {
    //TODO
}

class Team {
public:
    void add_user(Player* player) { listOfMembers.push_back(player); }
    vector<Player*> get_list_of_players() { return listOfMembers; }
private:
    vector<Player*> listOfMembers;
    string teamname;
};

Player* search_in_players(vector<Player>& listOfPlayers, string username) {
    for (auto& Player : listOfPlayers) {
        if (Player.get_username() == username)
            return &Player;
    }
    return NULL;
}

void initialising_for_round(vector<Player>& listOfPlayers, string winner) {
    for (auto& Player : listOfPlayers) {
        if (Player.get_teamname() == winner)
            Player.add_money(WIN_PRIZE);   
        else 
            Player.add_money(LOSE_PRIZE);
    }
}

void end_game() {

}

int main() {
    GameMode gameMode = START_MENU;
    vector<Player> listOfAllPlayers;
    Team terrorist, counterTerrorist;
    int numOfRounds;
    cin >> numOfRounds;
    while (numOfRounds--) {

    }

    return 0;
}