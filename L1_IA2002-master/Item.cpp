#include "Item.h"

Item::Item() {
    name = "empty";
    Atk = 0;
}

Item::Item(string Name, int ATK, string Category) {
    name = Name;
    Atk = ATK;
    category = Category;
}

const string &Item::getName() const {
    return name;
}

int Item::getAtk() const {
    return Atk;
}

const string &Item::getCategory() const {
    return category;
}
