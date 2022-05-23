#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__
#include <vector>
#include "passenger.hpp"
#include "driver.hpp"
#include "trip.hpp"
#include "location.hpp"

const std::string PASSENGER         = "passenger";
const std::string DRIVER            = "driver";
const std::string EMPTY             = "Empty";

constexpr int ALL_TRIPS_ID          = 0;

class DataBase {
public:
    DataBase() = default;
    ~DataBase();
    void add_location(Location* location);
    void check_and_add_person(std::string username, std::string role);
    void check_and_add_trip(Passenger* passenger, std::string origin, std::string destination);
    void show_trips(int id = ALL_TRIPS_ID);
    Trip* find_trip(int id);
    Person* find_person(std::string username);
    Location* find_location(std::string name);

private:
    void add_trip(Trip* trip); 
    void add_person(Person* person);
    std::vector<Location*> locations;
    std::vector<Person*> people;
    std::vector<Trip*> trips;
};

#endif