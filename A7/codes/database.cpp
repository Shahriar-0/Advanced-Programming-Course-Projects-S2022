#include "database.hpp"

DataBase::~DataBase() {
    for (auto i : people)
        delete i;
    for (auto i : locations)
        delete i;
    for (auto i : trips)
        delete i;
}

void DataBase::check_and_add_person(std::string username, std::string role) {
    Person* ptr = find_person(username);
    if (ptr != nullptr)
        throw ErrorHandler(BAD_REQUEST, "member already exists");
    
    if (role == DRIVER)
        add_person(new Driver(username));
    else if (role == PASSENGER)
        add_person(new Passenger(username));
}

Location* DataBase::find_location(std::string name) {
    for (auto it : locations) 
        if (*it == name)
            return it;
    return nullptr;
}

Person* DataBase::find_person(std::string username) {
    for (auto it : people) 
        if (*it == username)
            return it;
    return nullptr;
}

Trip* DataBase::find_trip(int id) {
    for (auto it : trips) 
        if (*it == id)
            return it;
    return nullptr;
}

void DataBase::add_trip(Passenger* passenger, std::string origin, std::string destination) { 
    Location* originLoc = find_location(origin);
    Location* destinationLoc = find_location(destination);
    
    if (originLoc == nullptr)
        throw ErrorHandler(NOT_FOUND, "origin not found");
    if (destinationLoc == nullptr)
        throw ErrorHandler(NOT_FOUND, "destination not found");

    //the + 1 is for id, cause each trip should have a unique id 
    trips.push_back(new Trip(passenger, trips.size() + 1, originLoc, destinationLoc));
}

void DataBase::add_location(Location* location) { locations.push_back(location); }
void DataBase::add_person(Person* person) { people.push_back(person); }