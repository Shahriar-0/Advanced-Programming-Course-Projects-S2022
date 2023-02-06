#include "game_manager.hpp"

typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

using namespace std;

GameManager::GameManager(game_manager_func_map_type& func_map) {
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

        Node* right_node = *find(nodes.begin(), nodes.end(), right_node_id);
        Node* left_node = *find(nodes.begin(), nodes.end(), left_node_id);


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

void GameManager::run(std::map<std::string, std::string> args){
    
}

void GameManager::close_station(std::map<std::string, std::string> args){
    
}

void GameManager::add_player(std::map<std::string, std::string> args){
    
}

void GameManager::shutdown(std::map<std::string, std::string> args){
    
}

template <typename T>
T* createInstance(int _id, T* parent, T* right, T* left) { 
    return new T(_id, parent, right, left); 
}
