#include "trip.hpp"

Trip::Trip(Passenger* _passenger, int _id) : passenger(_passenger), id(_id) {
    state = ON_GOING;
}

void Trip::is_done() {
    driver->reached_destination();
    passenger->reached_destination();
    state = DONE;
}

void Trip::has_begun(Driver* _driver) {
    driver = _driver;
    driver->has_begun_a_journey(this);
    passenger->has_begun_a_journey(this);
    //it's kinda optional because we already assigned it to "on going" 
    //in line 4 inside the constructor
    //but I'm gonna leave it here for now
    state = ON_GOING;
}

bool Trip::operator==(int _id) const { return id == _id; }
void Trip::assign_driver(Driver* _driver) { driver = _driver; }