#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <algorithm>
#include <vector>
#include "passenger.hpp"
#include "driver.hpp"
#include "trip.hpp"
#include "location.hpp"

class DataBase {
public:
    DataBase() = default;
    ~DataBase();
    void add_location(Location* location);
    void add_person(Person* person);
    void add_trip(Trip* trip);
    Trip* find_trip(int id);
    Person* find_person(std::string username);
    Location* find_location(std::string name);
private:
    std::vector<Location*> locations;
    std::vector<Person*> people;
    std::vector<Trip*> trips;
};

#endif