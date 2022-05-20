#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

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
private:
    std::vector<Location*> locations;
    std::vector<Person*> people;
    std::vector<Trip*> trips;
};

#endif