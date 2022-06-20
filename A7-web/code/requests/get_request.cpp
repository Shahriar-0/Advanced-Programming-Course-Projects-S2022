#include "get_request.hpp"

GetRequest::GetRequest(std::string line) : SystemRequest(line) {
    originName = destinationName = EMPTY_STRING;
    person = nullptr;
    inHurry = false;
    int idIndex = find_index(ID_KEYWORD);
    //here opposite the other scenarios it's alright not to pass an id
    id = (idIndex == NOT_FOUND_INDEX) ? EMPTY_ID : stoi(commands[idIndex]);
    check_for_type();

    if (type == COST)
        check_for_cost_validation();
    else if (type == GET_TRIPS)
        check_for_trips_validation();
}

void GetRequest::check_for_type() {
    std::string firstWord = commands[0];
    if (getRequestCommands[GET_TRIPS] == firstWord) 
        type = GET_TRIPS;
    else if (getRequestCommands[COST] == firstWord) 
        type = COST;
    else
        throw ErrorHandler(NOT_FOUND, "not one of get-request commands");
}

void GetRequest::check_for_trips_validation() {
    if (id != EMPTY_ID)
        return; //here we check for sort_by_cost parameter if we have id there's no need to sort

    int sortIndex = find_index(SORT_BY_COST_KEYWORD);
    if (sortIndex == NOT_FOUND_INDEX)
        throw ErrorHandler(BAD_REQUEST, "sorting value not found in command");

    sortByCost = (commands[sortIndex] == AGREE)? true : false;
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

void GetRequest::handle(DataBase& database, Response* response) {
    person = database.find_person(username);
    if (person == nullptr)
            throw ErrorHandler(NOT_FOUND, "person not found");

    if (type == GET_TRIPS) 
        handle_trips(database);
    else if (type == COST) 
        handle_cost(database);
}

void GetRequest::handle_trips(DataBase& database) {
    person->can_see_trips();
    database.show_trips(id, sortByCost);
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
    std::cout << std::fixed << std::setprecision(2) << trip.calculate_cost() << std::endl;
}