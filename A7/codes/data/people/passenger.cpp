#include "passenger.hpp"
#include "trip.hpp"

Passenger::Passenger(std::string _username) : Person(_username) {}

void Passenger::can_ask_for_trip() {
    if (state == IS_TRAVELING)
        throw ErrorHandler(BAD_REQUEST, "can't be in two trips simultaneously");
    //this function is called last so if we are here then it's alright to proceed 
    has_asked_for_trip();
}

void Passenger::has_reached_destination() {
    state = FINISHED;
    trip = nullptr;
}

void Passenger::has_asked_for_trip() { state = IS_WAITING; }
void Passenger::can_accept_a_trip(Trip* _trip) { throw ErrorHandler(PERMISSION_DENIED, "passengers can't accept trip"); }