#include "magazine.hh"

Magazine::Magazine(std::string _title, int _year, int _number) : Document(_title), year(_year), number(_number) {};

void Magazine::extend() {
    if (can_be_extended()) {
        //we never get here cause the can_be_extended function will return false
    }
}

bool Magazine::can_be_extended() const {
    errorHandler->show_error(RENEWING_A_MAGAZINE);
    return false;   //for now it's not renewable
}

int Magazine::calculate_penalty() const {
    int dayLate = dayPassed - maxDay;   
    int penalty = 0;
    
    if (year < CHANGING_PRICE_YEAR)
        penalty = dayLate * BEFORE_1390_PENALTY;
    else 
        penalty = dayLate * AFTER_1390_PENALTY;
    
    return penalty;
}