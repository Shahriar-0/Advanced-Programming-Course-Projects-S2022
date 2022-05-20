#include "database.hpp"

DataBase::~DataBase() {
    for (auto i : people)
        delete i;
    for (auto i : locations)
        delete i;
    for (auto i : trips)
        delete i;
}

void DataBase::add_location(Location* location) {
    locations.push_back(location);
}

void DataBase::add_person(Person* person) {
    people.push_back(person);
}

void DataBase::add_trip(Trip* trip) {
    trips.push_back(trip);
}

Location* DataBase::find_location(std::string name) {
    std::vector<Location*>::iterator it;
    it = std::find(locations.begin(), locations.end(), name);
    if (it == locations.end())
        throw ErrorHandler(NOT_FOUND, "location is not available");
    return *it;
}

Person* DataBase::find_person(std::string username) {
    std::vector<Person*>::iterator it;
    it = std::find(people.begin(), people.end(), username);
    if (it == people.end())
        throw ErrorHandler(NOT_FOUND, "person is not available");
    return *it;
}

Trip* DataBase::find_trip(int id) {
    std::vector<Trip*>::iterator it;
    it = std::find(trips.begin(), trips.end(), id);
    if (it == trips.end())
        throw ErrorHandler(NOT_FOUND, "trip is not available");
    return *it;
}