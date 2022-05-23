#include "delete_request.hpp"

DeleteRequest::DeleteRequest(std::string line) : Request(line) {
    int idIndex = find_index(ID_KEYWORD);
    if (idIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "id not found in command");
    id = stoi(commands[idIndex]);
}

void DeleteRequest::handle(DataBase& database) {
    
}