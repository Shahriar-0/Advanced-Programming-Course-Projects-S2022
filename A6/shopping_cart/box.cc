#include "box.hh"

Box::Box(int _id) : Object(_id) {}

int Box::get_evaluated() {
    int result = 0;
    for (auto& object : objectsInside)
        result += object->get_evaluated();
    int totalWeight = get_weight();
    result += (totalWeight < 20)? totalWeight / 2 : totalWeight / 10;
    return result;
}

int Box::get_weight() {
    int result = 0;
    for (auto& object : objectsInside) 
        result += object->get_weight();
    return result;
}

void Box::add_to_box(Object* obj) {
    objectsInside.push_back(obj);
}