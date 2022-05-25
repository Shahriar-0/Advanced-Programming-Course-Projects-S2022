#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <string>
#include "error_handler.hpp"

class Trip;
const std::string SUCCESS_MESSAGE   = "OK";
enum PersonState { IS_TRAVELING, IS_WAITING, FINISHED };

class Person {
public:
    Person(std::string username);
    virtual void can_accept_a_trip(Trip* trip) = 0;
    virtual void can_ask_for_a_trip() = 0;
    virtual void can_finish_a_trip(Trip* trip) = 0;
    virtual void can_see_trips() = 0;
    void reached_destination();
    void has_begun_a_journey(Trip* _trip);
    bool operator==(std::string username) const;
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
protected:
    std::string username;
    PersonState state;
    Trip* trip;
};

#endif