#include "database.hpp"

DataBase::~DataBase() {
    for (auto i : people)
        delete i;
    for (auto i : locations)
        delete i;
    for (auto i : trips)
        delete i;
}

Location* DataBase::find_location(std::string name) {
    std::vector<Location*>::iterator it;
    it = std::find(locations.begin(), locations.end(), name);
    if (it == locations.end())
        return nullptr;
    return *it;
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

Person* DataBase::find_person(std::string username) {
    std::vector<Person*>::iterator it;
    it = std::find(people.begin(), people.end(), username);
    if (it == people.end())
        return nullptr;
    return *it;
}

Trip* DataBase::find_trip(int id) {
    std::vector<Trip*>::iterator it;
    it = std::find(trips.begin(), trips.end(), id);
    if (it == trips.end())
        return nullptr;
    return *it;
}

void DataBase::add_location(Location* location) { locations.push_back(location); }
void DataBase::add_person(Person* person) { people.push_back(person); }
void DataBase::add_trip(Trip* trip) { trips.push_back(trip); }