#include "game_manager.hpp"

typedef void (GameManager::*game_manager_method)(std::vector<std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

using namespace std;

GameManager::GameManager(game_manager_func_map_type& func_map) : is_working(true) {
    load_nodes();
    map_functions(func_map);
}

void GameManager::load_nodes() {
    // Load all nodes from input file

    int num_nodes;
    cin >> num_nodes;
    vector<Node*> nodes;
    while (num_nodes--) {
        int node_id, right_node_id, left_node_id;
        string type;
        cin >> node_id >> right_node_id >> left_node_id >> type;

        auto right_node_it = find(nodes.begin(), nodes.end(), right_node_id);
        auto left_node_it = find(nodes.begin(), nodes.end(), left_node_id);
        Node* right_node = (right_node_it != nodes.end()) ? *right_node_it : nullptr;
        Node* left_node = (left_node_it != nodes.end()) ? *left_node_it : nullptr;


        Node* node;

        if (node_id > num_nodes) 
            node = createInstance<QueueNode>(node_id, nullptr, right_node, left_node);

        else {
            if (type == CHESS_KEYWORD) 
                node = createInstance<Chess>(node_id, nullptr, right_node, left_node);
            else if (type == WRESTLE_KEYWORD) 
                node = createInstance<Wrestle>(node_id, nullptr, right_node, left_node);
            else if (type == ARMWRESTLE_KEYWORD) 
                node = createInstance<ArmWrestle>(node_id, nullptr, right_node, left_node);
            else if (type == KABAB_KEYWORD)
                node = createInstance<Kabab>(node_id, nullptr, right_node, left_node);
            else 
                throw logic_error("Invalid node type");
        }
    }

    root_node = *find_if(nodes.begin(), nodes.end(), [](Node* node) { return node->is_root(); });
}

void GameManager::map_functions(game_manager_func_map_type& game_manager_function_map) {
    // Map all strings to the function map

    game_manager_function_map[ARRIVAL_KEYWORD] = &GameManager::add_player;
    game_manager_function_map[RUN_KEYWORD] = &GameManager::run;
    game_manager_function_map[END_GAME_KEYWORD] = &GameManager::shutdown;
    game_manager_function_map[CLOSE_KEYWORD] = &GameManager::close_station;

}

void GameManager::run(std::vector<std::string> args){
    
}

void GameManager::close_station(std::vector<std::string> args){
    
}

enum Arrival { 
    ARRIVAL_KEYWORD_INDEX,
    QUEUE_INDEX,
    PLAYER_INDEX,
    STRENGTH_INDEX,
    AGILITY_INDEX,
    INTELLIGENCE_INDEX,
    MAIN_ABILITY_INDEX 
};



void GameManager::add_player(std::vector<std::string> args){
    Player* player = new Player(stoi(args[PLAYER_INDEX]), stoi(args[STRENGTH_INDEX]),
                     stoi(args[AGILITY_INDEX]), stoi(args[INTELLIGENCE_INDEX]), args[MAIN_ABILITY_INDEX]);
    root_node->add_player(player, stoi(args[QUEUE_INDEX]));
}

void GameManager::shutdown(std::vector<std::string> args){
    
}

template <typename T>
T* createInstance(int _id, T* parent, T* right, T* left) { 
    return new T(_id, parent, right, left); 
}
