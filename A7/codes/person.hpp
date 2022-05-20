#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <cstring>
#include <string>

class Trip;

enum State { IS_TRAVELING, IS_WAITING, FINISHED };

class Person {
public:
    Person(std::string username);
    virtual void can_accept_a_trip() = 0;
    virtual void can_ask_for_trip() = 0;
    virtual void has_asked_for_trip() = 0;
    void add_trip(Trip* trip);
    void reached_destination();
protected:
    std::string username;
    State state;
    Trip* trip;
};

#endif