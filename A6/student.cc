#include "student.hh"
 
Student::Student(std::string _name, std::string _id) : Person(_name), id(_id) {}

bool Student::can_borrow(std::string title) {
    if (documents.size() == MAX_STUDENT_BORROW)
        errorHandler->show_error(EXCEEDED_MAX_BORROW);
    return Person::can_borrow(title);
}