#include "delete_request.hpp"

DeleteRequest::DeleteRequest(std::string line) : Request(line) {
    int idIndex = find_index(ID_KEYWORD);
    check_for_type();
    if (idIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "id not found in command");
    id = stoi(commands[idIndex]);
}

void DeleteRequest::check_for_type() {
    if (DeleteRequestCommands[0] == commands[0])
        return; //this line should change if we add more commands for get request
    throw ErrorHandler(BAD_REQUEST, "not one of delete-request commands");
}

void DeleteRequest::handle(DataBase& database) {
    
}