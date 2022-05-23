#include "post_request.hpp"

PostRequest::PostRequest(std::string _line) : Request(_line) {
    origin = destination = role = EMPTY_STRING;
    id = EMPTY_ID;

    if (type == FINISH || type == ACCEPT)
        check_for_finish_and_accept_validation();
    if (type == TRIPS)
        check_for_trips_validation();
    if (type == SIGNUP)
        check_for_signup_validation();
}

void PostRequest::check_for_type() {
    std::string firstWord = commands[0];
    if (firstWord == postRequestCommands[SIGNUP])
        type = SIGNUP;
    else if (firstWord == postRequestCommands[TRIPS])
        type = TRIPS;
    else if (firstWord == postRequestCommands[FINISH])
        type = FINISH;
    else if (firstWord == postRequestCommands[ACCEPT])
        type = ACCEPT;
    else 
        throw ErrorHandler(BAD_REQUEST, "not one of the post-request commands");
}


void PostRequest::check_for_finish_and_accept_validation() {
    int idIndex = find_index(ID_KEYWORD);
    if (idIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "id not found in command");

    id = stoi(commands[idIndex]);
}

void PostRequest::check_for_trips_validation() {
    int originId = find_index(ORIGIN_KEYWORD);
    int destinationId = find_index(DESTINATION_KEYWORD);
    if (originId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "origin not found in command");
    if (destinationId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "destination not found in command");
    
    origin = commands[originId];
    destination = commands[destinationId];
}

void PostRequest::check_for_signup_validation() {
    int roleIndex = find_index(ROLE_KEYWORD);
    if (roleIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "role not found");

    role = commands[roleIndex];
}

void PostRequest::handle(DataBase& database) {
    
}