#include "cli.hpp"

using namespace std;

CLI::CLI() {
    
}

vector<string> CLI::split_input_by_delimeter(string line, char delimeter) {
    vector<string> internal;
    stringstream ss(line); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimeter)) 
        internal.push_back(tok);

    return internal;
}

