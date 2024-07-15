#ifndef __BOOK_HH__
#define __BOOK_HH__
#include <vector>
#include  <iostream>
#include "object.hh"

class Box : public Object {
public:
    Box(int _id);
    virtual void add_to_box(Object* obj);
    virtual int get_evaluated();
    virtual int get_weight();
private:
    std::vector<Object*> objectsInside;
};

#endif 