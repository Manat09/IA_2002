#ifndef L1_IA2002_FIGHT_H
#define L1_IA2002_FIGHT_H
#include "Character.h"
#include "Enemy.h"
#include <iostream>

class Fight {
public:
    Fight();
    void startFight(Character character, Enemy enemy);
    void endFight(Character character, bool win);
private:
    bool win;


};


#endif //L1_IA2002_FIGHT_H
