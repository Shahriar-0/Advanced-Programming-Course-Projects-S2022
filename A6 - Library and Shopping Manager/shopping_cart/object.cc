#include "object.hh"

Object::Object(int _id) : id(_id) {}
bool Object::operator ==(int _id) const { return id == _id; }