#include "Item.h"

Item::Item() {
    this->name = "Test";
    this->Atk = 0;
}

Item::Item(string name, int Atk, string category) {
    this->name = name;
    this->Atk = Atk;
    this->category = category;
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
