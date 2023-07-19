#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Gun;
class Player;
class Team;
class GameManager;
#define MAX_MONEY 10000
#define WIN_PRIZE 2700
#define LOSE_PRIZE 2400
#define INITIAL_HEALTH 100
#define INITIAL_MONEY 1000

enum PlayerMode { AFK,
                  ATK };
enum GameMode { BEFORE_START_MENU,
                START_MENU,
                DURING_GAME,
                FINISHED };
enum PlayerStatus { DEAD,
                    ALIVE };
enum ErrosList { PLAYER_NOT_AVAILABLE,
                 CANT_BUY,
                 WEAPON_NOT_AVAILABLE,
                 ALREADY_HAVE,
                 INSUFFICIENT_MONEY,
                 DOESNT_HAVE_GUN,
                 FRIENDLY_FIRE,
                 NOT_STARTED,
                 ATTACKER_DEAD,
                 ATTACKED_DEAD };

class Gun {
   public:
    Gun(int _price, int _damage, int _prizeForKilling, string _name) {
        price = _price;
        damage = _damage;
        prizeForKilling = _prizeForKilling;
        name = _name;
    }
    bool operator==(Gun gun) { return name == gun.get_name(); }
    int get_price() { return price; }
    int get_damage() { return damage; }
    int get_prize_for_killing() { return prizeForKilling; }
    string get_name() { return name; }

   private:
    string name;
    int price;
    int damage;
    int prizeForKilling;
};
const Gun GUN_NOT_AVAILABLE(0, 0, 0, "NOT AVAILABLE");

class Player {
   public:
    int get_money() { return money; }
    int get_health() { return health; }
    string get_username() { return username; }
    string get_teamname() { return teamname; }
    PlayerMode get_mode() { return mode; }
    PlayerStatus get_status() { return status; }
    int get_kills() { return kills; }
    int get_deaths() { return deaths; }
    vector<Gun> get_list_of_guns() { return listOfGuns; }
    void set_status(PlayerStatus _status) { status = _status; }
    void go_AFK() { mode = AFK; }
    void go_ATK() { mode = ATK; }
    void empty_guns() { listOfGuns.clear(); }

    Player(string, string);
    void initialise(GameManager*);
    void add_money(int);
    void get_shot(Gun);
    bool has_gun(Gun);
    void shoot(GameManager*);
    bool can_shoot(Gun, Player*, GameManager*);
    void buy(GameManager*);
    bool can_buy(Gun, GameManager*);

   private:
    int kills;
    int deaths;
    int money;
    int health;
    string teamname;
    string username;
    vector<Gun> listOfGuns;
    PlayerMode mode;
    PlayerStatus status;
};

class Team {
   public:
    Team(string _teamname) { teamname = _teamname; }
    void add_user(Player player, GameManager* cs_go) {
        player.initialise(cs_go);
        listOfMembers.push_back(player);
    }
    vector<Player> get_list_of_players() { return listOfMembers; }
    void set_list_of_players(vector<Player> listOfPlayers) { listOfMembers = listOfPlayers; }
    string get_name() { return teamname; }

    int count_alive();
    void sorting();
    Player* search(string);
    void win();
    void lose();
    void initialise(GameManager*);
    void score_board();

   private:
    string teamname;
    vector<Player> listOfMembers;
};

class GameManager {
   public:
    GameManager();
    void before_menu();
    void menu();
    void fight();
    void end_game();
    void add_user();
    void initialising();
    void get_money_of_a_user();
    void get_health_of_a_user();
    void going_AFK();
    void going_ATK();
    void buying();
    void shooting();
    void score_board();
    void clearing();
    Gun search_weapon(Gun);
    void show_error(ErrosList);
    void get_command_in_start_menu(int&, int);
    void get_command_during_game(int&, int);
    void get_command_before_start_menu(int&);
    Gun convert_name_to_gun(string);
    Player* search_in_players(string);
    GameMode get_mode() { return gameMode; }

   private:
    vector<Gun> listOfAllGuns;
    Team terrorist, counter_terrorist;
    GameMode gameMode;
};

Gun GameManager::search_weapon(Gun gun) {
    for (auto i : listOfAllGuns)
        if (i == gun)
            return i;
    return GUN_NOT_AVAILABLE;
}

GameManager::GameManager() : terrorist("terrorist"), counter_terrorist("counter-terrorist") {
    listOfAllGuns.push_back(Gun(3000, 45, 100, "heavy"));
    listOfAllGuns.push_back(Gun(400, 20, 200, "pistol"));
    listOfAllGuns.push_back(Gun(0, 35, 500, "knife"));
}

void Team::win() {
    cout << teamname << " won" << endl;
    for (auto& player : listOfMembers)
        player.add_money(WIN_PRIZE);
}

void Team::lose() {
    for (auto& player : listOfMembers)
        player.add_money(LOSE_PRIZE);
}

Player::Player(string _username, string _teamname) {
    username = _username;
    teamname = _teamname;
    status = DEAD;
    health = INITIAL_HEALTH;
    money = INITIAL_MONEY;
    mode = ATK;
    kills = deaths = 0;
}

void Player::initialise(GameManager* cs_go) {
    if (status == DEAD) {
        empty_guns();
        listOfGuns.push_back(cs_go->convert_name_to_gun("knife"));
    }
    status = ALIVE;
    health = INITIAL_HEALTH;
}

void Team::initialise(GameManager* cs_go) {
    for (auto& player : listOfMembers)
        player.initialise(cs_go);
}

bool player_compare(Player& first, Player& second) {
    return first.get_kills() > second.get_kills() ||
           (first.get_deaths() < second.get_deaths() && first.get_kills() == second.get_kills()) ||
           (first.get_deaths() == second.get_deaths() && first.get_kills() == second.get_kills() && first.get_username() < second.get_username());
}

void Team::score_board() {
    sorting();
    cout << get_name() << " players:" << endl;
    for (auto i : listOfMembers)
        cout << i.get_username() << " " << i.get_kills() << " " << i.get_deaths() << endl;
}

void GameManager::score_board() {
    counter_terrorist.score_board();
    terrorist.score_board();
}

void Team::sorting() {
    sort(listOfMembers.begin(), listOfMembers.end(), player_compare);
}

void GameManager::show_error(ErrosList error) {
    switch (error) {
        case PLAYER_NOT_AVAILABLE:
            cout << "user not available" << endl;
            break;
        case CANT_BUY:
            cout << "you can't buy weapons anymore" << endl;
            break;
        case WEAPON_NOT_AVAILABLE:
            cout << "weapon not available" << endl;
            break;
        case ALREADY_HAVE:
            cout << "you already have this weapon" << endl;
            break;
        case INSUFFICIENT_MONEY:
            cout << "insufficient money" << endl;
            break;
        case DOESNT_HAVE_GUN:
            cout << "attacker doesn't have this gun" << endl;
            break;
        case FRIENDLY_FIRE:
            cout << "you can't shoot this player" << endl;
            break;
        case NOT_STARTED:
            cout << "The game hasn't started yet" << endl;
            break;
        case ATTACKER_DEAD:
            cout << "attacker is dead" << endl;
            break;
        case ATTACKED_DEAD:
            cout << "attacked is dead" << endl;
            break;
    }
}

bool Player::has_gun(Gun gun) {
    for (auto& playerGun : listOfGuns) {
        if (playerGun == gun)
            return true;
    }
    return false;
}

Player* Team::search(string username) {
    for (auto& player : listOfMembers) {
        if (player.get_username() == username)
            return &player;
    }
    return nullptr;
}

int Team::count_alive() {
    int result = 0;
    for (auto i : listOfMembers)
        result += (i.get_status() == ALIVE && i.get_mode() == ATK);
    return result;
}

void Player::get_shot(Gun gun) {
    health -= gun.get_damage();
    if (health <= 0) {
        health = 0;
        status = DEAD;
    }
}

void Player::add_money(int income) {
    money += income;
    if (money > MAX_MONEY)
        money = MAX_MONEY;
}

bool Player::can_shoot(Gun gun, Player* attacked, GameManager* cs_go) {
    if (attacked == nullptr || get_mode() == AFK || attacked->get_mode() == AFK) {
        cs_go->show_error(PLAYER_NOT_AVAILABLE);
        return false;
    }
    if (get_status() == DEAD) {
        cs_go->show_error(ATTACKER_DEAD);
        return false;
    }
    if (attacked->get_status() == DEAD) {
        cs_go->show_error(ATTACKED_DEAD);
        return false;
    }
    if (!has_gun(gun)) {
        cs_go->show_error(DOESNT_HAVE_GUN);
        return false;
    }
    if (get_teamname() == attacked->get_teamname()) {
        cs_go->show_error(FRIENDLY_FIRE);
        return false;
    }
    if (cs_go->get_mode() == START_MENU) {
        cs_go->show_error(NOT_STARTED);
        return false;
    }
    return true;
}

Gun GameManager::convert_name_to_gun(string gunName) {
    for (auto gun : listOfAllGuns)
        if (gun.get_name() == gunName)
            return gun;
    return GUN_NOT_AVAILABLE;
}

Player* GameManager::search_in_players(string username) {
    Player* result = nullptr;
    result = terrorist.search(username);
    if (result == nullptr)
        result = counter_terrorist.search(username);
    return result;
}

void Player::shoot(GameManager* cs_go) {
    string attackedName, gunName;
    cin >> attackedName >> gunName;
    Gun gun = cs_go->convert_name_to_gun(gunName);
    Player* attacked = cs_go->search_in_players(attackedName);
    if (can_shoot(gun, attacked, cs_go)) {
        attacked->get_shot(gun);
        if (attacked->get_status() == DEAD) {
            add_money(gun.get_prize_for_killing());
            attacked->deaths++;
            kills++;
        }
        cout << "nice shot" << endl;
    }
}

bool Player::can_buy(Gun gun, GameManager* cs_go) {
    if (status == DEAD || mode == AFK) {
        cs_go->show_error(PLAYER_NOT_AVAILABLE);
        return false;
    }
    if (cs_go->get_mode() == DURING_GAME) {
        cs_go->show_error(CANT_BUY);
        return false;
    }
    if (gun == GUN_NOT_AVAILABLE) {
        cs_go->show_error(WEAPON_NOT_AVAILABLE);
        return false;
    }
    if (has_gun(gun)) {
        cs_go->show_error(ALREADY_HAVE);
        return false;
    }
    if (money < gun.get_price()) {
        cs_go->show_error(INSUFFICIENT_MONEY);
        return false;
    }
    return true;
}

void Player::buy(GameManager* cs_go) {
    string gunName;
    cin >> gunName;
    Gun gun = cs_go->convert_name_to_gun(gunName);
    if (can_buy(gun, cs_go)) {
        listOfGuns.push_back(gun);
        money -= gun.get_price();
        cout << "weapon bought successfully" << endl;
    }
}

void GameManager::end_game() {
    if (counter_terrorist.count_alive() > 0) {
        counter_terrorist.win();
        terrorist.lose();
    } else {
        terrorist.win();
        counter_terrorist.lose();
    }
}

void GameManager::add_user() {
    string username, teamname;
    cin >> username >> teamname;
    (teamname == "terrorist") ? terrorist.add_user(Player(username, teamname), this) : counter_terrorist.add_user(Player(username, teamname), this);
    cout << "ok" << endl;
}

void GameManager::get_money_of_a_user() {
    string username;
    cin >> username;
    cout << search_in_players(username)->get_money() << endl;
}

void GameManager::get_health_of_a_user() {
    string username;
    cin >> username;
    cout << search_in_players(username)->get_health() << endl;
}

void GameManager::going_AFK() {
    string username;
    cin >> username;
    search_in_players(username)->go_AFK();
    cout << "ok" << endl;
}

void GameManager::going_ATK() {
    string username;
    cin >> username;
    search_in_players(username)->go_ATK();
    cout << "ok" << endl;
}

void GameManager::buying() {
    string username;
    cin >> username;
    search_in_players(username)->buy(this);
}

void GameManager::shooting() {
    string username;
    cin >> username;
    search_in_players(username)->shoot(this);
}

void GameManager::get_command_in_start_menu(int& iteration, int numOfCommands) {
    string command;
    while (gameMode == START_MENU && iteration < numOfCommands) {
        cin >> command;
        if (command == "start") {
            gameMode = DURING_GAME;
            cout << "fight!" << endl;
        } else if (command == "get-money")
            get_money_of_a_user();
        else if (command == "get-health")
            get_health_of_a_user();
        else if (command == "go-afk")
            going_AFK();
        else if (command == "go-atk")
            going_ATK();
        else if (command == "buy")
            buying();
        else if (command == "shoot")
            shooting();
        else if (command == "score-board")
            score_board();
        iteration++;
    }
}

void GameManager::get_command_during_game(int& iteration, int numOfCommands) {
    string command;
    while (iteration < numOfCommands) {
        cin >> command;
        if (command == "get-money")
            get_money_of_a_user();
        else if (command == "get-health")
            get_health_of_a_user();
        else if (command == "go-afk")
            going_AFK();
        else if (command == "go-atk")
            going_ATK();
        else if (command == "buy")
            buying();
        else if (command == "score-board")
            score_board();
        else if (command == "shoot")
            shooting();
        iteration++;
    }
}

void GameManager::get_command_before_start_menu(int& numOfCommand) {
    string command;
    while (gameMode == BEFORE_START_MENU) {
        cin >> command;
        if (command == "add-user")
            add_user();
        else if (command == "round") {
            gameMode = START_MENU;
            cin >> numOfCommand;
        } else if (command == "buy")
            buying();
        else if (command == "shoot")
            shooting();
        else if (command == "score-board")
            score_board();
    }
}

void GameManager::initialising() {
    terrorist.initialise(this);
    counter_terrorist.initialise(this);
    gameMode = BEFORE_START_MENU;
}

void GameManager::clearing() {
    string command;
    while (cin >> command && command == "score-board")
        score_board();
}

int main() {
    GameManager cs_go;
    int numOfRounds;
    cin >> numOfRounds;
    while (numOfRounds--) {
        cs_go.initialising();
        int numOfCommands;
        cs_go.get_command_before_start_menu(numOfCommands);
        int iteration = 0;
        cs_go.get_command_in_start_menu(iteration, numOfCommands);
        cs_go.get_command_during_game(iteration, numOfCommands);
        cs_go.end_game();
    }
    cs_go.clearing();
}