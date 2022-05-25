#include "request.hpp"


Request::Request(std::string line) {
    split_input_line(line);

    //cause every request has a username in it 
    int usernameIndex = find_index(USERNAME_KEYWORD);
    if (usernameIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "username not found in command");
    username = commands[usernameIndex];
}

int Request::find_index(std::string word) {
    for (int i = 0; i < commands.size() - 1; i++) 
        if (commands[i] == word)
            return i + 1;       //this is because every word comes after it's corresponding command 
    return NOT_FOUND_INDEX;
}

void Request::split_input_line(std::string line) {
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(COMMAND_DELIMITER)) != std::string::npos) {
        token = line.substr(0, pos);
        commands.push_back(token);
        line.erase(0, pos + 1);
    }
    commands.push_back(line);
}