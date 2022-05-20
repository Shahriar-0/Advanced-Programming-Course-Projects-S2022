#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <cstring>
#include <string>
#include "error_handler.hpp"

class Trip;

enum PersonState { IS_TRAVELING, IS_WAITING, FINISHED };

class Person {
public:
    Person(std::string username);
    virtual void can_accept_a_trip(Trip* trip) = 0;
    virtual void can_ask_for_trip() = 0;
    void reached_destination();
    void has_begun_a_journey(Trip* _trip);
    bool operator==(std::string username) const;
protected:
    std::string username;
    PersonState state;
    Trip* trip;
};

#endif