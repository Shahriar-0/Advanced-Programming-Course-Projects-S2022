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
    
    if (role == DRIVER_KEYWORD)
        add_person(new Driver(username));
    else if (role == PASSENGER_KEYWORD)
        add_person(new Passenger(username));
    else 
        throw ErrorHandler(BAD_REQUEST, "roles can only be driver and passenger");
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

void DataBase::show_trips(int id, bool sortedByCist) {
    if (id != ALL_TRIPS_ID) {
        Trip* trip = find_trip(id);
        if (trip == nullptr || trip->is_cancelled())
            std::cout << EMPTY_KEYWORD << std::endl;
        else
            std::cout << *trip;
    }
    else {
        if (!check_for_trip_existence()) 
            std::cout << EMPTY_KEYWORD << std::endl;
        else {
            (sortedByCist) ? show_all_trips_cost() : show_all_trips_id();
        }
    }
}

void DataBase::show_all_trips_id() const {
    for (auto it : trips) 
        std::cout << *it;
}

bool compare(const Trip* first, const Trip* second) { return first->cost < second->cost; }

void DataBase::show_all_trips_cost() const {
    std::vector<Trip*> sortedByCostTrips(trips);
    std::sort(sortedByCostTrips.begin(), sortedByCostTrips.end(), compare);
    for (auto it : sortedByCostTrips) 
        std::cout << *it;
}

bool DataBase::check_for_trip_existence() const {
    if (trips.size() == 0)
        return false;
    for (auto it : trips)
        if (!it->is_cancelled())
            return true;
    return false;
}

void DataBase::check_and_add_trip(Passenger* passenger, std::string origin, std::string destination, bool inHurry) { 
    Location* originLoc = find_location(origin);
    Location* destinationLoc = find_location(destination);
    
    if (originLoc == nullptr)
        throw ErrorHandler(NOT_FOUND, "origin not found");
    if (destinationLoc == nullptr)
        throw ErrorHandler(NOT_FOUND, "destination not found");

    //the + 1 is for id, cause each trip should have a unique id 
    add_trip(new Trip(passenger, trips.size() +  1, originLoc, destinationLoc, inHurry));
}

void DataBase::add_location(Location* location) { locations.push_back(location); }
void DataBase::add_trip(Trip* trip) { trips.push_back(trip); std::cout << trips.size() << std::endl; }
void DataBase::add_person(Person* person) { people.push_back(person); std::cout << SUCCESS_MESSAGE << std::endl; }