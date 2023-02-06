#include "cli.hpp"

using namespace std;

CLI::CLI() : game_manager(game_manager_func_map) {
    // game_manager_function_map["new"] = &run;
    // game_manager_func_map_type m;
    // m["new"] = &run;
    std::map<std::string, void (CLI::*)()> m;
    m["new"] = &CLI::run;
}

vector<string> CLI::split_input_by_delimeter(string line, char delimeter) {
    vector<string> internal;
    stringstream ss(line); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimeter)) 
        internal.push_back(tok);

    return internal;
}

