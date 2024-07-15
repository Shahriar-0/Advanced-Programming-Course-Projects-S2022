#ifndef __ITEM_HH__
#define __ITEM_HH__
#include "object.hh"
#include <string>
#include <cstring>
#include <iostream>

const std::string NOT_BOX = "Not a box";

class Item : public Object {
public:
    Item(int _id, int _cost, int _weight);
    virtual void add_to_box(Object* obj);
    virtual int get_evaluated();
    virtual int get_weight();
private:
    int cost, weight;
};

#endif