#ifndef __CART_MANAGER_HH__
#define __CART_MANAGER_HH__
#include "item.hh"
#include "box.hh"

const std::string ALREADY_EXITS = "Item already exists in cart";
const std::string NOT_FOUND = "Not found in cart";
constexpr int INDEX_NOT_FOUND = -1;

class CartManager {
public:
    CartManager();
    ~CartManager();
    void add_item(int id, int cost, int weight);
    void add_box(int id);
    void add_to_box(int box_id, int id);
    int evaluate_cart();
private:
    bool is_unique(int id);
    int search(int id);
    std::vector<Object*> objects;
};

#endif
