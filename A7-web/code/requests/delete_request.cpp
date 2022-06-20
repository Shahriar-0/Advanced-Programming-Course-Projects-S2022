#include "delete_request.hpp"

DeleteRequest::DeleteRequest(std::string line) : SystemRequest(line) {
    int idIndex = find_index(ID_KEYWORD);
    check_for_type();
    if (idIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "id not found in command");
    id = stoi(commands[idIndex]);
}

void DeleteRequest::check_for_type() {
    if (DeleteRequestCommands[0] == commands[0])
        return; //this line should change if we add more commands for get request
    throw ErrorHandler(NOT_FOUND, "not one of delete-request commands");
}

void DeleteRequest::handle(DataBase& database, Response* response) {
    Trip* trip = database.find_trip(id);
    if (trip == nullptr) 
        throw ErrorHandler(NOT_FOUND, "trip does not exist");
    if (!trip->is_for_this_passenger(username))
        throw ErrorHandler(PERMISSION_DENIED, "you can't cancel other's trip");
    trip->has_cancelled();
}