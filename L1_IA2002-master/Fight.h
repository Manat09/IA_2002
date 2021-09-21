#ifndef L1_IA2002_FIGHT_H
#define L1_IA2002_FIGHT_H
#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include "windows.h"//use this library for sleep() func.


class Fight {
public://show that this functions will be public
    Fight();
    void startFight(Character character, Enemy enemy);
    void endFight(Character character, bool win);
    bool aliveCheck(Character character, Enemy enemy);

private:
    bool win;


};


#endif //L1_IA2002_FIGHT_H
