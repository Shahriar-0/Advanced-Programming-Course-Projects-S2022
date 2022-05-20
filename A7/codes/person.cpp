#include "person.hpp"
#include "trip.hpp"

Person::Person(std::string _username) : username(_username) {
    trip = nullptr;
    state = FINISHED;
}

void Person::add_trip(Trip* _trip) {
    trip = _trip;
    state = IS_TRAVELING;
}

void Person::reached_destination() {
    trip = nullptr;
    state = FINISHED;
}