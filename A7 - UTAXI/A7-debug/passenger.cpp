#include "passenger.hpp"
#include "trip.hpp"

Passenger::Passenger(std::string _username) : Person(_username) {}

void Passenger::can_ask_for_a_trip() {
    if (state == IS_TRAVELING)
        throw ErrorHandler(BAD_REQUEST, "can't be in two trips simultaneously");
    //this function is called last so if we are here then it's alright to proceed 
    has_asked_for_trip();
}

std::ostream& operator<<(std::ostream& out, const Passenger& passenger) {
    out << passenger.username;
    return out;
}

void Passenger::has_cancelled() { state = FINISHED; }
void Passenger::has_asked_for_trip() { state = IS_WAITING; }
void Passenger::can_finish_a_trip(Trip* _trip) { throw ErrorHandler(PERMISSION_DENIED, "passenger can't finish a trip"); }
void Passenger::can_accept_a_trip(Trip* _trip) { throw ErrorHandler(PERMISSION_DENIED, "passengers can't accept trip"); }
void Passenger::can_see_trips() { throw ErrorHandler(PERMISSION_DENIED, "passengers can't see trips"); }