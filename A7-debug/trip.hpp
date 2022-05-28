#ifndef __TRIP_HPP__
#define __TRIP_HPP__

#include <iostream>
#include <cstring>
#include "driver.hpp"
#include "passenger.hpp"
#include "location.hpp"

class Person;

enum TripState { DONE, ON_GOING, NOT_ACCEPTED_YET, CANCELLED };

class Trip {
public:
    Trip(Passenger* passenger, int id, Location* origin, Location* destination);
    void has_ended();
    void has_begun(Driver* driver);
    void has_cancelled();
    bool is_cancelled() const;
    bool can_be_accepted() const;
    bool is_for_this_passenger(std::string username) const;
    bool can_get_canceled() const;

    bool operator==(int _id) const;
    bool operator!=(Trip _trip) const;
    
    friend std::ostream& operator<<(std::ostream& out, const Trip& trip);
private:
    Passenger* passenger;
    Driver* driver;
    Location* origin;
    Location* destination;
    TripState state;
    int id;
};

#endif