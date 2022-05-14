#include "refernce.hh"


Reference::Reference(std::string _title) : Document(_title) {};

void Reference::extend() {
    if (can_be_extended()) {
        maxDay += REFERNCE_RETURN_TIME_PERIOD;
        numOfExtension++;
    }
}

bool Reference::can_be_extended() const {
    if (numOfExtension == REFERNCE_MAX_EXTENSION)
        errorHandler->show_error(EXCEEDED_MAX_RENEW);
    //there's an exit in show error function so if we pass that point it's allright
    return Document::can_be_extended();
}

int Reference::calculate_penalty() const {
    int dayLate = dayPassed - maxDay;   
    int penalty = 0;
    
    if (dayLate < 0)
        return penalty;

    if (dayLate <= FIRST_PENALTY_PERIOD_REFERENCE)
        penalty = dayLate * FIRST_PENALTY_REFERENCE;
    else 
        penalty = FIRST_PENALTY_PERIOD_REFERENCE * FIRST_PENALTY_REFERENCE +
          (dayLate - FIRST_PENALTY_PERIOD_REFERENCE) * SECOND_PENALTY_REFERENCE;
        
    return penalty;
}

void Reference::is_getting_borrowed() {
    dayPassed = 0;
    maxDay = REFERNCE_RETURN_TIME_PERIOD;
}