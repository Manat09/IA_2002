#ifndef L1_IA2002_GAME_H
#define L1_IA2002_GAME_H
#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Character.h"
#include "Item.h"
#include "Fight.h"
using namespace std;

class Game {//class game
public:
    Game();
    void mainMenu();
    void startMenu();
    void exploreMenu();
    int getChoice() const;
    bool isPlaying() const;
    Enemy chooseEnemy();
private:
    int choice;
    bool playing;




};


#endif //L1_IA2002_GAME_H
