#include "person.hpp"
#include "../trip/trip.hpp"

Person::Person(std::string _username) : username(_username) {
    trip = nullptr;
    state = FINISHED;
}

void Person::reached_destination() {
    trip = nullptr;
    state = FINISHED;
}

void Person::has_begun_a_journey(Trip* _trip) {
    trip = _trip;
    state = IS_TRAVELING;
}

bool Person::operator==(std::string _username) const { return username == _username; }