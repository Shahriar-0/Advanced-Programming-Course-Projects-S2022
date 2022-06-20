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

void GetRequest::handle(DataBase& database, Response* response, std::string username) {
    person = database.find_person(username);
    if (person == nullptr)
            throw ErrorHandler(NOT_FOUND, "person not found");

    if (type == GET_TRIPS) 
        handle_trips(database, response, username);
    else if (type == COST) 
        handle_cost(database, response);
}

void GetRequest::handle_trips(DataBase& database, Response* response, std::string username) {
    person->can_see_trips();
    database.show_trips(id, sortByCost, response, username);
}

void GetRequest::handle_cost(DataBase& database, Response* response) {
    Location* origin = database.find_location(originName);
    Location* destination = database.find_location(destinationName);
    if (origin == nullptr || destination == nullptr)
        throw ErrorHandler(NOT_FOUND, "origin or destination not found");
    
    Passenger* passenger = dynamic_cast<Passenger*> (person);
    if (passenger == NULL)
        throw ErrorHandler(PERMISSION_DENIED, "not a passenger");

    Trip trip(origin, destination, inHurry);
    double cost = trip.calculate_cost();
    cost = ceil(cost * 100) / 100.0;
    
    std::string body;
    body += "<!DOCTYPE html><html><head><link rel='stylesheet' href='home.css'><meta charset='UTF-8'><style>a:link";
    body += "{color: rgb(0, 0, 0);background-color: transparent;text-decoration: none;width:100%; font-size: xx-large;display:block;text-align: center;text-align: center;";
    body += "a:visited {color: rgb(65, 15, 212);background-color: transparent;text-decoration: none;width:100%; font-size: xx-large; display:block;text-align: center;}";
    body += "a:hover {color: rgb(23, 71, 194);background-color: transparent;text-decoration: underline;width:100%; font-size: xx-large;display:block;text-align: center;}";
    body += "a:active {color: yellow;background-color: transparent;text-decoration: underline;width:100%; font-size: xx-large;display:block; text-align: center;}";
    body += "</style></head><body class='body'><div><br/><br/><br/><br/><p style='text-align: center;'>";
    body += "your trip cost is: ";
    body += std::to_string(cost);
    body += "</p><a href='/'>home</a><br></div></body></html>";
    response->setBody(body);
}