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
#include <math.h>

#include "../nodes/queue_node.hpp"
#include "../nodes/game_station.hpp"
#include "../nodes/node.hpp"
#include "../nodes/chess.hpp"
#include "../nodes/wrestle.hpp"
#include "../nodes/armwrestle.hpp"
#include "../nodes/kabab.hpp"


std::string STRONG_KEYWORD = "strong";
std::string AGILE_KEYWORD = "agile";
std::string INTELLIGENT_KEYWORD = "intelligent";

const std::string CHESS_KEYWORD = "chess";
const std::string WRESTLE_KEYWORD = "wrestle";
const std::string ARMWRESTLE_KEYWORD = "armwrestle";
const std::string KABAB_KEYWORD = "kabab";

class GameManager {
public:
    GameManager() = default;
    ~GameManager() = default;

    void run(std::vector<std::string> args);
    void close_station(std::vector<std::string> args);
    void add_player(std::vector<std::string> args);
    
    void shutdown(std::vector<std::string> args);
    bool is_running();
private:
    void load_nodes();
    void split_line(int& node_id, int& left_node_id, int& right_node_id, std::string& node_type, std::string& line);
    void find_left_and_right(Node*& left, Node*& right, std::vector<Node*>& nodes, int left_node_id, int right_node_id);
    void add_node(std::string line, std::vector<Node*>& nodes, int num_nodes);
    Node* root_node;
    bool is_working;
    template<typename T> T* createInstance(int _id, Node* right, Node* left);
};



#endif