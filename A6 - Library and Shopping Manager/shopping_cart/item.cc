#include "item.hh"

Item::Item(int _id, int _cost, int _weight) : Object(_id), cost(_cost), weight(_weight) {};
void Item::add_to_box(Object* obj) { std::cout << NOT_BOX << std::endl; exit(EXIT_SUCCESS); }
int Item::get_evaluated() { return cost; }
int Item::get_weight() { return weight; }
