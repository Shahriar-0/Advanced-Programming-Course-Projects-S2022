#include "trip.hpp"

Trip::Trip(Passenger* _passenger, int _id, Location* _origin, Location* _destination)
    : passenger(_passenger), id(_id), origin(_origin), destination(_destination) {
    state = NOT_ACCEPTED_YET;
} 

void Trip::has_ended() {
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

void Trip::is_cancelled() {
    passenger->has_cancelled();
    //we haven't assign a driver so there is no need to do anything about it
}

bool Trip::is_for_this_passenger(std::string username) const { return *passenger == username; }
bool Trip::can_get_canceled() const { return state == NOT_ACCEPTED_YET; }
bool Trip::can_be_accepted() const { return state == NOT_ACCEPTED_YET; }
bool Trip::operator==(int _id) const { return id == _id; }
bool Trip::operator!=(Trip _trip) const { return id != _trip.id; }