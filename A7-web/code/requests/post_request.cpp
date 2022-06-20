#include "post_request.hpp"

PostRequest::PostRequest(std::string _line) : SystemRequest(_line) {
    origin = destination = role = EMPTY_STRING;
    id = EMPTY_ID;
    person = nullptr;
    trip = nullptr;
    check_for_type();
    if (type == FINISH || type == ACCEPT)
        check_for_finish_and_accept_validation();
    else if (type == POST_TRIPS)
        check_for_trips_validation();
    else if (type == SIGNUP)
        check_for_signup_validation();
}

void PostRequest::check_for_type() {
    std::string firstWord = commands[0];
    if (firstWord == postRequestCommands[SIGNUP])
        type = SIGNUP;
    else if (firstWord == postRequestCommands[POST_TRIPS])
        type = POST_TRIPS;
    else if (firstWord == postRequestCommands[FINISH])
        type = FINISH;
    else if (firstWord == postRequestCommands[ACCEPT])
        type = ACCEPT;
    else 
        throw ErrorHandler(NOT_FOUND, "not one of the post-request commands");
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
    int inHurryIndex = find_index(IN_HURRY_KEYWORD);
    if (originId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "origin not found in command");
    if (destinationId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "destination not found in command");
    if (inHurryIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "in hurry not found in command");

    origin = commands[originId];
    destination = commands[destinationId];    
    inHurry = (commands[inHurryIndex] == AGREE)? true : false;
}

void PostRequest::check_for_signup_validation() {
    int roleIndex = find_index(ROLE_KEYWORD);
    if (roleIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "role not found");

    role = commands[roleIndex];
}

void PostRequest::handle(DataBase& database, Response* response) {
    if (type == SIGNUP)
        handle_signup(database);    
    else {
        //other functions require person
        person = database.find_person(username);
        if (person == nullptr)
            throw ErrorHandler(NOT_FOUND, "person not found");
        
        if (type == POST_TRIPS) {
            handle_trips(database, response);
            return;
        }

        //other functions require trip and person
        trip = database.find_trip(id);
        if (trip == nullptr)
            throw ErrorHandler(NOT_FOUND, "trip not found");
        
        if (type == ACCEPT)
            handle_accept(database);    
        if (type == FINISH)
            handle_finish(database);    
        //cause we checked the type there's no need for else here    
    }
}

void PostRequest::handle_trips(DataBase& database, Response* response) {
    person->can_ask_for_a_trip();

    Passenger* passenger = dynamic_cast<Passenger*> (person);
    if (passenger == NULL)
        throw ErrorHandler(PERMISSION_DENIED, "not a passenger");

    database.check_and_add_trip(passenger,  origin, destination, inHurry, response);
}

void PostRequest::handle_signup(DataBase& database) { database.check_and_add_person(username, role); }
void PostRequest::handle_accept(DataBase& database) { person->can_accept_a_trip(trip); }
void PostRequest::handle_finish(DataBase& database) { person->can_finish_a_trip(trip); }