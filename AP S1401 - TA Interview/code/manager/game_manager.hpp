#ifndef __GAME_MANAGER_HPP__
#define __GAME_MANAGER_HPP__

#include <string>
#include <cstring>
#include <map>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <exception>

#include "../nodes/queue_node.hpp"
#include "../nodes/game_station.hpp"
#include "../nodes/node.hpp"
#include "../nodes/chess.hpp"
#include "../nodes/wrestle.hpp"
#include "../nodes/armwrestle.hpp"
#include "../nodes/kabab.hpp"


// typedef void (*game_manager_method)(std::map<std::string, std::string>);
// typedef std::map<std::string, game_manager_method> game_manager_func_map_type;
// typedef std::map<std::string, std::function<void(std::map<std::string, std::string>)>> game_manager_func_map_type;

typedef void (GameManager::*game_manager_method)(std::vector<std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;
typedef std::map<std::string, Node*(*)()> string_to_node_map;

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

    void run(std::vector<std::string> args);
    void close_station(std::vector<std::string> args);
    void add_player(std::vector<std::string> args);
    
    void shutdown(std::vector<std::string> args) { is_working = false; } ;
    bool is_running() { return is_working; }
private:
    void load_nodes();
    void map_functions(game_manager_func_map_type& game_manager_function_map);
    Node* root_node;
    string_to_node_map stations_type;
    bool is_working;
    template <typename T> T* createInstance(int _id, Node* parent, Node* right, Node* left);
};



#endif