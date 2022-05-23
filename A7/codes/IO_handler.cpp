#include "IO_handler.hpp"

IOHandler::IOHandler(std::string _filename) : filename(_filename) {}

void IOHandler::read_locations(DataBase& database) {
    std::ifstream input(filename);
    std::string tempLine;
    input >> tempLine;
    Location tempLoc;
    try {
        while (input >> tempLine) {
            tempLine >> tempLoc;
            database.add_location(new Location(tempLoc));
        }
    }
    catch (ErrorHandler& error) {
        error.show_error(); 
    }
}

Request* IOHandler::generate_request() {
    std::string line;
    getline(std::cin, line);
    size_t index = line.find(COMMAND_DELIMITER);
    std::string type = line.substr(0, index);
    if (type == RequestTypeString[GET])
        return new GetRequest(line.substr(index + 1));
    else if (type == RequestTypeString[POST])
        return new PostRequest(line.substr(index + 1));
    else if (type == RequestTypeString[DELETE])
        return new DeleteRequest(line.substr(index + 1));
    else 
        throw ErrorHandler(BAD_REQUEST, "not one of the three basic types");
}