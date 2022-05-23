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
    
}