#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>

#include "../nodes/queue_node.hpp"
#include "../nodes/game_station.hpp"


// typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
// typedef std::map<std::string, game_manager_method> game_manager_func_map_type;
// typedef std::map<std::string, std::function<void(std::map<std::string, std::string>)>> game_manager_func_map_type;

typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;


const std::string RUN_KEYWORD = "run";
const std::string END_GAME_KEYWORD = "$";
const std::string CLOSE_KEYWORD = "close";
const std::string ARRIVAL_KEYWORD = "arrival";

std::string STRONG_KEYWORD = "strong";
std::string AGILE_KEYWORD = "agile";
std::string INTELLIGENT_KEYWORD = "intelligent";

const std::string CHESS_KEYWORD = "chess";
const std::string WRESTLE_KEYWORD = "wrestle";
const std::string ARMWRESTLE_KEYWORD = "armwrestle";
const std::string KABAB_KEYWORD = "kabab";

class GameManager {
public:
    GameManager(game_manager_func_map_type& game_manager_function_map);
    ~GameManager() = default;

    void run(std::map<std::string, std::string> args);
    void close_station(std::map<std::string, std::string> args);
    void add_player(std::map<std::string, std::string> args);
    void shutdown(std::map<std::string, std::string> args);
    
    class Player {
    public:
        Player(int _id, int _power, int _speed, int _intelligence, std::string main_ability);
        ~Player();
    private:
        int *main_trait;
        int power;
        int speed;
        int intelligence;
        int id;
        int win;
    };

    class Node {
    public:
        Node(int _id, GameManager::Node* _parent = nullptr, GameManager::Node* _right = nullptr,
            GameManager::Node* _left = nullptr) : id(_id), parent(_parent), right(_right), left(_left) {};
        ~Node() = default;
        virtual void add_player(Player* player) = 0;
    protected:
        int id;
        Node* right;
        Node* left;
        Node* parent;
    };


private:
    void map_names_to_game_station_type();
    void load_nodes();
    void map_functions(game_manager_func_map_type& game_manager_function_map);
    Node* root_node;
    std::map<std::string, GameManager::Node*> stations_type;

};



#endif