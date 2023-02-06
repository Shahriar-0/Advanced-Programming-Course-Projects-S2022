#include "cli.hpp"

using namespace std;

CLI::CLI() : game_manager(game_manager_func_map) {
    while (game_manager.is_running()) {
        string line;
        getline(cin, line);
        vector<string> input = split_input_by_delimeter(line, ' ');
        string command = input[0];
        game_manager_func_map[command](input);
    }
}

vector<string> CLI::split_input_by_delimeter(string line, char delimeter) {
    vector<string> internal;
    stringstream ss(line); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimeter)) 
        internal.push_back(tok);

    return internal;
}

