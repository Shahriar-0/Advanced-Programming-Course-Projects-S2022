#ifndef __PASSENGER_HPP__
#define __PASSENGER_HPP__

#include "error_handler.hpp"
#include "request.hpp"
#include "person.hpp"

class Passenger : public Person {
public:
    Passenger(std::string username);
    virtual void can_accept_a_trip();
    virtual void can_ask_for_trip();
private:
    void has_asked_for_trip();
};

#endif