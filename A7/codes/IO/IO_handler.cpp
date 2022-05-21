#include "IO_handler.hpp"

IOHandler::IOHandler(std::string _filename) : filename(_filename) {}

void IOHandler::read_locations(DataBase& database) {
    std::ifstream input(filename);
    Location tempLoc;
    while (input >> tempLoc) 
        database.add_location(new Location(tempLoc));
}