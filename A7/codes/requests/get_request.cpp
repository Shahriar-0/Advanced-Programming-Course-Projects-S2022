#include "get_request.hpp"

GetRequest::GetRequest(std::string line) : Request(line) {
    originName = destinationName = EMPTY_STRING;
    person = nullptr;
    inHurry = false;
    int idIndex = find_index(ID_KEYWORD);
    //here opposite the other scenarios it's alright not to pass an id
    id = (idIndex == NOT_FOUND_INDEX) ? EMPTY_ID : stoi(commands[idIndex]);
    check_for_type();
    //trips validation is done in the constructor of Request
    //so we only need to check for cost
    if (type == COST)
        check_for_cost_validation();
}

void GetRequest::check_for_type() {
    std::string firstWord = commands[0];
    if (getRequestCommands[TRIPS] == firstWord) 
        type = TRIPS;
    else if (getRequestCommands[COST] == firstWord) 
        type = COST;
    else
        throw ErrorHandler(NOT_FOUND, "not one of get-request commands");
}

void GetRequest::check_for_cost_validation() {
    int originId = find_index(ORIGIN_KEYWORD);
    int destinationId = find_index(DESTINATION_KEYWORD);
    int inHurryIndex = find_index(IN_HURRY_KEYWORD);
    if (originId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "origin not found in command");
    if (destinationId == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "destination not found in command");
    if (inHurryIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "in hurry not found in command");

    originName = commands[originId];
    destinationName = commands[destinationId];
    inHurry = (commands[inHurryIndex] == AGREE)? true : false;
}

void GetRequest::handle(DataBase& database) {
    person = database.find_person(username);
    if (person == nullptr)
            throw ErrorHandler(NOT_FOUND, "person not found");

    if (type == TRIPS) 
        handle_trips(database);
    else if (type == COST) 
        handle_cost(database);
    
}

void GetRequest::handle_trips(DataBase& database) {
    person->can_see_trips();
    database.show_trips(id, inHurry);
}

void GetRequest::handle_cost(DataBase& database) {
    Location* origin = database.find_location(originName);
    Location* destination = database.find_location(destinationName);
    if (origin == nullptr || destination == nullptr)
        throw ErrorHandler(NOT_FOUND, "origin or destination not found");
    
    Passenger* passenger = dynamic_cast<Passenger*> (person);
    if (passenger == NULL)
        throw ErrorHandler(PERMISSION_DENIED, "not a passenger");

    Trip trip(origin, destination, inHurry);
    std::cout << trip.calculate_cost() << std::endl;
}