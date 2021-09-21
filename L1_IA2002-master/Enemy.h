#ifndef L1_IA2002_ENEMY_H
#define L1_IA2002_ENEMY_H
#include <string>
using namespace std;
//class Enemy
class Enemy {
public://showws that this functions will be public
    Enemy(string name,int HP, int maxHP,int atk);

    const string &getName() const;

    int getHp() const;

    int getMaxHp() const;

    int getAtk() const;

    void setHp(int hp);


private://shows that this values will be private
    string name;
    int HP;
    int maxHP;
    int atk;
};


#endif //L1_IA2002_ENEMY_H
