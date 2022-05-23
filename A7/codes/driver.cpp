#include "driver.hpp"
#include "trip.hpp"

Driver::Driver(std::string _username) : Person(_username) {}

void Driver::can_accept_a_trip(Trip* _trip) {
    if (state == IS_TRAVELING)
        throw ErrorHandler(BAD_REQUEST, "you still have a passenger");
    //this function is checked last so if we're here then it's alright to proceed
    has_accepted_a_trip(_trip);
}

void Driver::can_finish_a_trip(Trip* _trip) {
    if (state != IS_TRAVELING)
        throw ErrorHandler(BAD_REQUEST, "you don't have a passenger");
    
    if (*_trip != *trip)
        throw ErrorHandler(PERMISSION_DENIED, "you can only finish a your trip");
    
    trip->is_done();
}

void Driver::has_accepted_a_trip(Trip* _trip) {
    state = IS_TRAVELING;
    trip->has_begun(this);
}

void Driver::can_ask_for_a_trip() { throw ErrorHandler(PERMISSION_DENIED, "driver can't ask for a trip"); }