#ifndef L1_IA2002_CHARACTER_H
#define L1_IA2002_CHARACTER_H

//#include "Game.h"
#include "Item.h"
#include <iomanip>
using namespace std;



class Character {
public:
    Character();
    void createCharacter(string name);
    string toStringStats();
    void gainExp(int exp);

public:
    const string &getName() const;

    int getHp() const;

    int getMaxHp() const;

    int getAtk() const;

    int getLevel() const;

    int getExp() const;



public:
    void setName(const string &name);

    void setHp(int hp);

    void setMaxHp(int maxHp);

    void setAtk(int atk);

    void setLevel(int level);

    void setExp(int exp);

    void lootItem(Item item);

private:
    string name;
    int HP;
    int maxHP;
    int Atk;
    int level;
    int exp;
    Item item[3];//slot 0 weapon, slot 1 armor, slot 2 legs

public:
    double getExpNext() const;

    void setExpNext(double expNext);

};


#endif //L1_IA2002_CHARACTER_H
