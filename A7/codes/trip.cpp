#include "trip.hpp"

Trip::Trip(Passenger* _passenger, int _id, Location* _origin, Location* _destination)
    : passenger(_passenger), id(_id), origin(_origin), destination(_destination) {} 

void Trip::is_done() {
    driver->reached_destination();
    passenger->reached_destination();
    state = DONE;
}

void Trip::has_begun(Driver* _driver) {
    driver = _driver;
    driver->has_begun_a_journey(this);
    passenger->has_begun_a_journey(this);
    state = ON_GOING;
}

bool Trip::operator==(int _id) const { return id == _id; }
bool Trip::operator!=(Trip _trip) const { return id != _trip.id; }