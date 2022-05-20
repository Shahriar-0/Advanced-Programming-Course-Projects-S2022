#ifndef __TRIP_HPP__
#define __TRIP_HPP__

#include <iostream>
#include <cstring>
#include "driver.hpp"
#include "passenger.hpp"

class Person;

enum TripState { DONE, ON_GOING };

class Trip {
public:
    Trip(Passenger* passenger, int _id);
    void assign_driver(Driver* driver);
    void is_done();
    void has_begun(Driver* driver);
    bool operator==(int _id);
private:
    Passenger* passenger;
    Driver* driver;
    TripState state;
    int id;
};

#endif