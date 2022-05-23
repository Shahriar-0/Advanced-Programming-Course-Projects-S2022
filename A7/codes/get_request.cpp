#include "get_request.hpp"

GetRequest::GetRequest(std::string line) : Request(line) {
    int idIndex = find_index(ID_KEYWORD);

    //here opposite the other scenarios it's alright not to pass an id
    id = (idIndex == NOT_FOUND_INDEX) ? EMPTY_ID : stoi(commands[idIndex]);
}


void GetRequest::handle(DataBase& database) {
    
}