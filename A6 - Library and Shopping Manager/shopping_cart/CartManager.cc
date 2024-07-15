#include "CartManager.hh"

CartManager::CartManager() {}

CartManager::~CartManager() {
    for (auto& object : objects)
        delete object;
}

int CartManager::search(int _id) {
    for (int i = 0; i < objects.size(); i++) 
        if (*objects[i] == _id)
            return i;
    return INDEX_NOT_FOUND;
}

bool CartManager::is_unique(int id) {
    int index = search(id);
    if (index == INDEX_NOT_FOUND)
        return true;
    return false;
}

void CartManager::add_box(int _id) {
    if (is_unique(_id)) 
        objects.push_back(new Box(_id)); 
    else {
        std::cout << ALREADY_EXITS << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void CartManager::add_item(int _id, int _cost, int _weight) {
    if (is_unique(_id)) 
        objects.push_back(new Item(_id, _cost, _weight)); 
    else {
        std::cout << ALREADY_EXITS << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void CartManager::add_to_box(int box_id, int itemId) {
    int boxIndex = search(box_id), itemIndex = search(itemId);
    if (boxIndex == INDEX_NOT_FOUND || itemIndex == INDEX_NOT_FOUND) {
        std::cout << NOT_FOUND << std::endl;
        exit(EXIT_SUCCESS);
    }
    Object* box = objects[boxIndex]; 
    Object* item = objects[itemIndex]; 
    box->add_to_box(item);
    objects.erase(objects.begin() + itemIndex);
}

int CartManager::evaluate_cart() {
    int result = 0;
    for (auto& object : objects) 
        result += object->get_evaluated();
    return result;
}