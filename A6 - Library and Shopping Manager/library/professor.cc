#include "professor.hh"

Professor::Professor(std::string _name) : Person(_name) {}

bool Professor::can_borrow(std::string title) {
    if (documents.size() == MAX_PROFESSOR_BORROW)
        errorHandler->show_error(EXCEEDED_MAX_BORROW);
    return Person::can_borrow(title);
}
