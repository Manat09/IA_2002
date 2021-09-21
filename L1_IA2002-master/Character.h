#ifndef L1_IA2002_CHARACTER_H
#define L1_IA2002_CHARACTER_H

//#include "Game.h"
#include "Item.h"
#include <iomanip>
using namespace std;


//
class Character {
public://shows that this functions will be public
    Character();
    void createCharacter(string name);//our function that Create character
    string toStringStats();
    void gainExp(int exp);

public://shows that this functions will be public
    const string &getName() const;

    int getHp() const;

    int getMaxHp() const;

    int getAtk() const;

    int getLevel() const;

    int getExp() const;

    Item getItem(int slot) const;


public://show that this functions will be public
//as our values is private
//we use setter and getter methods
    void setName(const string &name);

    void setHp(int hp);

    void setMaxHp(int maxHp);

    void setAtk(int atk);

    void setLevel(int level);

    void setExp(int exp);

    int getGold();

    void gainGold(int gold);

    void setGold(int gold);

    void lootItem(Item item);

private://shows that this values will be private
    string name;
    int HP;
    int maxHP;
    int Atk;
    int level;
    int exp;
    int gold;
    Item item[3];

public://shows that this functions will be public
    double getExpNext() const;

    void setExpNext(double expNext);

};


#endif //L1_IA2002_CHARACTER_H
