#ifndef __TRIP_HPP__
#define __TRIP_HPP__

#include <iostream>
#include <cstring>
#include "driver.hpp"
#include "passenger.hpp"
#include "location.hpp"

class Person;

enum TripState { DONE, ON_GOING };

class Trip {
public:
    Trip(Passenger* passenger, int id, Location* origin, Location* destination);
    void is_done();
    void has_begun(Driver* driver);
    bool operator==(int _id) const;
    bool operator!=(Trip _trip) const;
private:
    Passenger* passenger;
    Driver* driver;
    Location* origin;
    Location* destination;
    TripState state;
    int id;
};

#endif