#include "request.hpp"

void Request::split_input_line(std::string line) {
    size_t pos = 0;
    std::string token;
    while ((pos = line.find(COMMAND_DELIMITER)) != std::string::npos) {
        token = line.substr(0, pos);
        commands.push_back(token);
        line = line.substr(0, pos + 1);
    }
    commands.push_back(line);
}