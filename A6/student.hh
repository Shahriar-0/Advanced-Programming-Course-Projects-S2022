#ifndef __STUDENT_HH__
#define __STUDENT_HH__
#include "person.hh"

constexpr int MAX_STUDENT_BORROW = 2;

class Student : public Person {
public:
    Student(std::string, std::string);
protected:
    virtual bool can_borrow(std::string);
private:
    std::string id;
};

#endif