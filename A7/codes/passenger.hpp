#ifndef __PASSENGER_HPP__
#define __PASSENGER_HPP__

#include "error_handler.hpp"
#include "person.hpp"

class Passenger : public Person {
public:
    Passenger(std::string username);
    virtual void can_accept_a_trip(Trip* _trip);
    virtual void can_ask_for_a_trip();
    virtual void can_finish_a_trip(Trip* _trip);
    virtual void can_see_trips();

    void has_cancelled();
    void has_found_a_driver();

    friend std::ostream& operator<<(std::ostream& out, const Passenger& passenger);
private:
    void has_asked_for_trip();
};

#endif