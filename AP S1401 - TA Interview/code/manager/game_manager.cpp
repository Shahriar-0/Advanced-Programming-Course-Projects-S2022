#include "game_manager.hpp"

// #include "../nodes/chess.cpp"
// #include "../nodes/armwrestle.cpp"
// #include "../nodes/wrestle.cpp"
// #include "../nodes/kabab.cpp"
// #include "../nodes/queue_node.cpp"

typedef void (GameManager::*game_manager_method)(std::map<std::string, std::string>);
typedef std::map<std::string, game_manager_method> game_manager_func_map_type;

using namespace std;

GameManager::GameManager(game_manager_func_map_type& func_map) {
    load_nodes();
    map_functions(func_map);
    map_names_to_game_station_type();
}

void GameManager::load_nodes() {
    // Load all nodes from input file

    int num_nodes;
    cin >> num_nodes;
    while (num_nodes--) {
        int node_id, right_node_id, left_node_id;
        string type;
        cin >> node_id >> right_node_id >> left_node_id >> type;

        Node* node;
        if (node_id > num_nodes) 
            node = new QueueNode(node_id);
        else {

        }
        // Node* node = new GameManager::Node(node_id);
        // if (root_node == nullptr) {
        //     root_node = node;
        // }
    }

}

void GameManager::map_functions(game_manager_func_map_type& game_manager_function_map) {
    // Map all strings to the function map

    game_manager_function_map[ARRIVAL_KEYWORD] = &GameManager::add_player;
    game_manager_function_map[RUN_KEYWORD] = &GameManager::run;
    game_manager_function_map[END_GAME_KEYWORD] = &GameManager::shutdown;
    game_manager_function_map[CLOSE_KEYWORD] = &GameManager::close_station;

}


void GameManager::map_names_to_game_station_type() {
    // Map all strings to the game station type


}