#ifndef __PASSENGER_HPP__
#define __PASSENGER_HPP__

#include "error_handler.hpp"
#include "request.hpp"
#include "person.hpp"

class Passenger : public Person {
public:
    Passenger(std::string username);
    virtual void can_accept_a_trip(Trip* _trip);
    virtual void can_ask_for_trip();

    void has_reached_destination();
    void has_found_a_driver();
private:
    void has_asked_for_trip();
};

#endif