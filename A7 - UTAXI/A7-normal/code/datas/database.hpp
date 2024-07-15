#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__
#include <vector>
#include <algorithm>
#include "passenger.hpp"
#include "driver.hpp"
#include "trip.hpp"
#include "location.hpp"

const std::string PASSENGER_KEYWORD = "passenger";
const std::string DRIVER_KEYWORD    = "driver";
const std::string EMPTY_KEYWORD     = "EMPTY";

constexpr int ALL_TRIPS_ID          = 0;

class DataBase {
public:
    DataBase() = default;
    ~DataBase();
    void add_location(Location* location);
    void check_and_add_person(std::string username, std::string role);
    void check_and_add_trip(Passenger* passenger, std::string origin, std::string destination, bool inHurry);
    void show_trips(int id, bool sortedByCist);
    Trip* find_trip(int id);
    Person* find_person(std::string username);
    Location* find_location(std::string name);

private:
    void show_all_trips_id() const;
    void show_all_trips_cost() const;
    bool check_for_trip_existence() const;
    void add_trip(Trip* trip); 
    void add_person(Person* person);
    std::vector<Location*> locations;
    std::vector<Person*> people;
    std::vector<Trip*> trips;
};

#endif