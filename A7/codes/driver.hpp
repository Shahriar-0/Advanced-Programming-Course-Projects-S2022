#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__

#include "person.hpp"

class Driver : public Person {
public:
    Driver(std::string username);
    virtual void can_ask_for_a_trip();
    virtual void can_accept_a_trip(Trip* _trip);
    virtual void can_finish_a_trip(Trip* _trip);
    virtual void can_see_trips();

private:
    void has_accepted_a_trip(Trip* _trip);
};

#endif