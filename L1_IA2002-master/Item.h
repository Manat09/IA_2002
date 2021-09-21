#ifndef L1_IA2002_ITEM_H
#define L1_IA2002_ITEM_H
#include <string>
using namespace std;

class Item {
public://shows that these functions will be public
    Item();
    Item(string name, int Atk, string category);

    const string &getName() const;

    int getAtk() const;

private://shows that this values will be private
    string name;
    int Atk;
    string category;
public://shows that this function will be public
    const string &getCategory() const;
};


#endif //L1_IA2002_ITEM_H
