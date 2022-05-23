#ifndef __DATABASE_HPP__
#define __DATABASE_HPP__

#include <algorithm>
#include <vector>
#include "passenger.hpp"
#include "driver.hpp"
#include "trip.hpp"
#include "location.hpp"

const std::string PASSENGER = "passenger";
const std::string DRIVER    = "driver";


class DataBase {
public:
    DataBase() = default;
    ~DataBase();
    void add_location(Location* location);
    void check_and_add_person(std::string username, std::string role);
    void add_trip(Trip* trip);
    Trip* find_trip(int id);
    Person* find_person(std::string username);
    Location* find_location(std::string name);

    void print_loc() {
        for (auto i : locations) 
            std::cout << *i;
    }
    
private:
    void add_person(Person* person);
    std::vector<Location*> locations;
    std::vector<Person*> people;
    std::vector<Trip*> trips;
};

#endif