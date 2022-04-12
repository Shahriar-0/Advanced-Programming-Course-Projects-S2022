#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Gun;
class Player;
class Team;
#define MAX_MONEY 10000
#define WIN_PRIZE 2700
#define LOSE_PRIZE 2400
#define INITIAL_HEALTH 100
#define INITIAL_MONEY 1000

enum PlayerMode {AFK, ATK};
enum GameMode {BEFORE_START_MENU, START_MENU, DURING_GAME, FINISHED};
enum PlayerStatus {DEAD, ALIVE};
enum ErrosList {PLAYER_NOT_AVAILABLE, CANT_BUY, WEAPON_NOT_AVAILABLE, ALREADY_HAVE,
    INSUFFICIENT_MONEY, DOESNT_HAVE_GUN, FRIENDLY_FIRE, NOT_STARTED, ATTACKER_DEAD, ATTACKED_DEAD};

class Gun {
public:
    Gun(){ name = "NOT AVAILABLE"; }
    Gun (int _price, int _damage, int _prizeForKilling, string _name) {
        price = _price;
        damage = _damage;
        prizeForKilling = _prizeForKilling;
        name = _name;
    }
    string name;
    int price;
    int damage;
    int prizeForKilling;
};

//some predefined variables
const Gun HEAVY(3000, 45, 100, "heavy");
const Gun PISTOL(400, 20, 200, "pistol");
const Gun KNIFE(0, 35, 500, "knife");

void show_error(ErrosList error) {
    switch(error) { 
        case PLAYER_NOT_AVAILABLE: cout << "user not available" << endl; break;
        case CANT_BUY: cout << "you can't buy weapons anymore" << endl; break;
        case WEAPON_NOT_AVAILABLE: cout << "weapon not available" << endl; break;
        case ALREADY_HAVE: cout << "you already have this weapon" << endl; break;
        case INSUFFICIENT_MONEY: cout << "insufficient money" << endl; break;
        case DOESNT_HAVE_GUN: cout << "attacker doesn' have this gun" << endl; break;
        case FRIENDLY_FIRE: cout << "you can't shoot this player" << endl; break;
        case NOT_STARTED: cout << "The game hasn't started yet" << endl; break;
        case ATTACKER_DEAD: cout << "attacker is dead" << endl; break;
        case ATTACKED_DEAD: cout << "attacked is dead" << endl; break;
    }
}

class Player {
public:
    Player (string, string);
    int get_money() { return money; }
    int get_health() { return health; }
    string get_username() { return username; }
    string get_teamname() { return teamname; }
    PlayerMode get_mode() { return mode; }
    PlayerStatus get_status() { return status; }
    int get_kills() { return kills; }
    int get_deaths() { return deaths; }
    void set_status(PlayerStatus _status) { status = _status; }
    vector<Gun> get_list_of_guns() { return listOfGuns; }
    void go_AFK() { mode = AFK; }
    void go_ATK() { mode = ATK; }
    void add_money(int);
    void get_shot(Gun);
    Gun* search_in_guns(Gun);
    void shoot(Team&, Team&, GameMode);
    bool can_shoot(Gun, Player*, GameMode);
    void buy(string, GameMode);
    bool can_buy(Gun, GameMode);
    void empty_guns() { listOfGuns.clear(); }
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

Player::Player (string _username, string _teamname) {
        username = _username;
        teamname = _teamname;
        status = ALIVE;
        health = INITIAL_HEALTH;
        money = INITIAL_MONEY;
        mode = ATK;
        kills = deaths = 0;
}

class Team {
public:
    void add_user(Player player) { listOfMembers.push_back(player); }
    vector<Player> get_list_of_players() { return listOfMembers; }
    int count_alive();
    Player* search(string);
private:
    vector<Player> listOfMembers;
    string teamname;
};

Gun* Player::search_in_guns(Gun gun) {
    for (auto& playerGun : get_list_of_guns()) {
        if (playerGun.name == gun.name)
            return &playerGun;
    }
    return NULL;
}

Player* Team::search(string username) {
    for (auto& player : get_list_of_players()) {
        if (player.get_username() == username)
            return &player;
    }
    return NULL;
}

int Team::count_alive() {
    int result = 0;
    for (auto i : listOfMembers)
        result += (i.get_status() == ALIVE && i.get_mode() == ATK);
    return result;
}

void Player::get_shot(Gun gun) {
    health -= gun.damage;
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

bool Player::can_shoot(Gun gun, Player* attacked, GameMode gameMode) {
    if (attacked == NULL || get_mode() == AFK || attacked->get_mode() == AFK) {
        show_error(PLAYER_NOT_AVAILABLE);
        return false;
    }
    else if (get_status() == DEAD) {
        show_error(ATTACKER_DEAD);
        return false;
    }
    else if (attacked->get_status() == DEAD) {
        show_error(ATTACKED_DEAD);
        return false;
    }
    else if (search_in_guns(gun) == NULL) {
        show_error(WEAPON_NOT_AVAILABLE);
        return false;
    }
    else if (get_teamname() == attacked->get_teamname()) {
        show_error(FRIENDLY_FIRE);
        return false;
    }
    else if (gameMode == START_MENU) {
        show_error(NOT_STARTED);
        return false;
    }
    return true;
}

Gun convert_name_to_gun(string gunName) {
    Gun gun;
    if (gunName == HEAVY.name)
        gun = HEAVY;
    else if (gunName == PISTOL.name)
        gun = PISTOL;
    else if (gunName == KNIFE.name)
        gun = KNIFE;
    return gun;
}

Player* search_in_players(Team& terrorist, Team& counter_terrorist, string username) {
    Player* result = NULL;
    result = terrorist.search(username);
    if (result == NULL)
        result = counter_terrorist.search(username);
    return result;
}

void Player::shoot(Team& terrorist, Team& counter_terrorist, GameMode gameMode) {
    string attackedName, gunName;
    cin >> attackedName >> gunName;
    Gun gun = convert_name_to_gun(gunName);
    Player* attacked = search_in_players(terrorist, counter_terrorist, attackedName);
    if (can_shoot(gun, attacked, gameMode)) {
        add_money(gun.prizeForKilling);
        attacked->get_shot(gun);
        if (attacked->get_status() == DEAD) {
            attacked->deaths++;
            kills++;
        }
        cout << "nice shot" << endl;
    }
}

bool Player::can_buy(Gun gun, GameMode gameMode) {
    if (status == DEAD || mode == AFK) {
        show_error(PLAYER_NOT_AVAILABLE);
        return false;
    }
    if (gameMode == DURING_GAME) {
        show_error(CANT_BUY);
        return false;
    }
    if (gun.name == "NOT AVAILABLE") {
        show_error(WEAPON_NOT_AVAILABLE);
        return false;
    }
    if (search_in_guns(gun) != NULL) {
        show_error(ALREADY_HAVE);
        return false;
    }
    if (money < gun.price) {
        show_error(INSUFFICIENT_MONEY);
        return false;
    }
    return true;
}

void Player::buy(string gunName, GameMode gameMode) {
    Gun gun = convert_name_to_gun(gunName);
    if (can_buy(gun, gameMode)) {
        listOfGuns.push_back(gun);
        money -= gun.price;
        cout << "weapon bought successfully" << endl;
    }
}

void end_game(Team& terrorist, Team& counter_terrorist) {
    string winner;
    if (counter_terrorist.count_alive() > 0)
        winner = "counter-terrorist";
    else 
        winner = "terrorist";
    cout << winner << " won" << endl;

    for (auto& Player : terrorist.get_list_of_players()) {
        if (winner == "terrorist")
             Player.add_money(WIN_PRIZE);
        else     
            Player.add_money(LOSE_PRIZE);
    }
    for (auto& Player : counter_terrorist.get_list_of_players()) {
        if (winner == "counter-terrorist")
             Player.add_money(WIN_PRIZE);
        else     
            Player.add_money(LOSE_PRIZE);
    }
}

void initialising_for_each_round(Team& terrorist, Team& counter_terrorist, GameMode& gameMode) {
    for (Player& player : terrorist.get_list_of_players()) {
        player.empty_guns();
        player.buy("knife", START_MENU);
    }
    for (Player& player : counter_terrorist.get_list_of_players()) {
        player.empty_guns();
        player.buy("knife", START_MENU);
    }
    gameMode = BEFORE_START_MENU;
}

void add_user(Team& terrorist, Team& counter_terrorist) {
    string username, teamname;
    cin >> username >> teamname;
    if (teamname == "terrorist")
        terrorist.add_user(Player(username, teamname));
    else 
        counter_terrorist.add_user(Player(username, teamname));
}

void get_money_of_a_user(Team& terrorist, Team& counter_terrorist) {
    string username;
    cin >> username;
    Player* player = search_in_players(terrorist, counter_terrorist, username);
    cout << player->get_money() << endl;
}

void get_health_of_a_user(Team& terrorist, Team& counter_terrorist) {
    string username;
    cin >> username;
    Player* player = search_in_players(terrorist, counter_terrorist, username);
    cout << player->get_health() << endl;
}

void going_afk(Team& terrorist, Team& counter_terrorist) {
    string username;
    cin >> username;
    Player* player = search_in_players(terrorist, counter_terrorist, username);
    player->go_AFK();
}

void going_atk(Team& terrorist, Team& counter_terrorist) {
    string username;
    cin >> username;
    Player* player = search_in_players(terrorist, counter_terrorist, username);
    player->go_ATK();
}

void buying (Team& terrorist, Team& counter_terrorist, GameMode gameMode) {
    string username, gunName;
    cin >> username >> gunName;
    Player* player = search_in_players(terrorist, counter_terrorist, username);
    player->buy(gunName, gameMode);
}

void shooting(Team& terrorist,Team& counter_terrorist, GameMode gameMode) {
    string attackerName;
    cin >> attackerName;
    Player* attacker = search_in_players(terrorist, counter_terrorist, attackerName);
    attacker->shoot(terrorist, counter_terrorist, gameMode);
}

bool player_compare(Player& first, Player& second) {
    return first.get_kills() < second.get_kills() ||
    (first.get_deaths() > second.get_deaths() && first.get_kills() == second.get_kills()) ||
    (first.get_deaths() == second.get_deaths() && first.get_kills() == second.get_kills() && first.get_username() < second.get_username());
}

void score_board(Team& terrorist, Team& counter_terrorist) {
    sort(terrorist.get_list_of_players().begin(), terrorist.get_list_of_players().end(), player_compare);
    sort(counter_terrorist.get_list_of_players().begin(), counter_terrorist.get_list_of_players().end(), player_compare);
    
    cout << "terrorist player:" << endl; 
    for (auto& player : terrorist.get_list_of_players()) 
        cout << player.get_username() << " " << player.get_kills() << " " << player.get_deaths() <<  endl;
    
    cout << "counter-terrorist player:" << endl; 
    for (auto& player : counter_terrorist.get_list_of_players()) 
        cout << player.get_username() << " " << player.get_kills() << " " << player.get_deaths() <<  endl;    
}

void get_command_in_start_menu(GameMode& gameMode, Team& terrorist, Team& counter_terrorist) {
    string command;
    cin >> command;
    if (command == "start") {
        gameMode = DURING_GAME;
        cout << "fight!" << endl;
    }
    else if (command == "get-money")
        get_money_of_a_user(terrorist, counter_terrorist);
    else if (command == "get-health")
        get_health_of_a_user(terrorist, counter_terrorist);
    else if (command == "go-afk")
        going_afk(terrorist, counter_terrorist);
    else if (command == "go-atk")
        going_atk(terrorist, counter_terrorist);
    else if (command == "buy")
        buying(terrorist, counter_terrorist, gameMode);
    else if (command == "shoot") 
        shooting(terrorist, counter_terrorist, gameMode);
    else if (command == "score-board")
        score_board(terrorist, counter_terrorist);
}

void get_command_during_game(GameMode& gameMode, Team& terrorist, Team& counter_terrorist) {
    string command;
    cin >> command;
    if (command == "get-money")
        get_money_of_a_user(terrorist, counter_terrorist);
    else if (command == "get-health")
        get_health_of_a_user(terrorist, counter_terrorist);
    else if (command == "go-afk")
        going_afk(terrorist, counter_terrorist);
    else if (command == "go-atk")
        going_atk(terrorist, counter_terrorist);
    else if (command == "buy")
        buying(terrorist, counter_terrorist, gameMode);
    else if (command == "score-board")
        score_board(terrorist, counter_terrorist);
    else if (command == "shoot")
        shooting(terrorist, counter_terrorist, gameMode);
}

void get_command_before_start_menu(GameMode& gameMode, Team& terrorist, Team& counter_terrorist, int& numOfCommand) {
    string command;
    cin >> command;
    if (command == "add-user")
        add_user(terrorist, counter_terrorist);
    else if (command == "round") {
        gameMode = START_MENU;
        cin >> numOfCommand;
    }
    else if (command == "buy")
        buying(terrorist, counter_terrorist, gameMode);
    else if (command == "shoot") 
        shooting(terrorist, counter_terrorist, gameMode);
}

int main() {
    GameMode gameMode = BEFORE_START_MENU;
    Team terrorist, counter_terrorist;
    int numOfRounds;
    cin >> numOfRounds;
    while (numOfRounds--) {
        initialising_for_each_round(terrorist, counter_terrorist, gameMode);
        int numOfCommands;
        while (gameMode == BEFORE_START_MENU)
            get_command_before_start_menu(gameMode, terrorist, counter_terrorist, numOfCommands);
        int iteration = 0;
        while (gameMode == START_MENU && iteration < numOfCommands) { 
            get_command_in_start_menu(gameMode, terrorist, counter_terrorist);
            iteration++;
        }
        while (iteration < numOfCommands) {
            get_command_during_game(gameMode, terrorist, counter_terrorist);
            iteration++;
        }
        end_game(terrorist, counter_terrorist);
    }
    return 0;
}