#include "get_request.hpp"

GetRequest::GetRequest(std::string line) : Request(line) {
    check_for_type();
    
    int idIndex = find_index(ID_KEYWORD);
    //here opposite the other scenarios it's alright not to pass an id
    id = (idIndex == NOT_FOUND_INDEX) ? EMPTY_ID : stoi(commands[idIndex]);
}

void GetRequest::check_for_type() {
    if (getRequestCommands[0] == commands[0])
        return; //this line should change if we add more commands for get request
    throw ErrorHandler(BAD_REQUEST, "not one of get-request commands");
}

void GetRequest::handle(DataBase& database) {
    database.show_trips(id);
}