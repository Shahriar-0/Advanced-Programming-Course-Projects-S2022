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