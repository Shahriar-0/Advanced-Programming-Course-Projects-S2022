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

const std::string RUN_KEYWORD = "Run";
const std::string END_GAME_KEYWORD = "$";
const std::string CLOSE_KEYWORD = "Close";
const std::string ARRIVAL_KEYWORD = "Arrival";

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
    void split_line(int& node_id, int& left_node_id, int& right_node_id, std::string& node_type, std::string& line);
    void find_left_and_right(Node*& left, Node*& right, std::vector<Node*>& nodes, int left_node_id, int right_node_id);
    void add_node(std::string line, std::vector<Node*>& nodes, int num_nodes);
    Node* root_node;
    string_to_node_map stations_type;
    bool is_working;
    template <typename T> T* createInstance(int _id, Node* parent, Node* right, Node* left);
};



#endif