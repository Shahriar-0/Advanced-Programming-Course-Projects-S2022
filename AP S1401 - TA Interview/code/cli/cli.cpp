#include "cli.hpp"

using namespace std;

CLI::CLI() : game_manager(game_manager_func_map) {
    
}

vector<string> CLI::split_input_by_delimeter(string line, char delimeter) {
    vector<string> internal;
    stringstream ss(line); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimeter)) 
        internal.push_back(tok);

    return internal;
}

void CLI::run() {
    while (game_manager.is_running()) {
        string line;
        getline(cin, line);
        vector<string> input = split_input_by_delimeter(line, ' ');
        string command = input[0];
        try {
            // auto func = game_manager_func_map.find(command);
            // if (func != game_manager_func_map.end())
            //     (game_manager.*(func->second))(input);
            // else
            //     throw std::invalid_argument("Invalid command");
            game_manager_func_map[command](input);
        }
        catch (const std::exception& e) {
            cout << e.what() << endl;
        }
    }
}