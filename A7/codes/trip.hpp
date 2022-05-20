#ifndef __TRIP_HPP__
#define __TRIP_HPP__

#include <iostream>
#include <cstring>
#include "driver.hpp"
#include "passenger.hpp"

class Person;

class Trip {
public:
    Trip(Passenger* passenger);
};

#endif