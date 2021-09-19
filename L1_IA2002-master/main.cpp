#include "Game.h"
//Inventory with 3 best items
//Fight system
//Enemy class

int countChoices;
int main() {

    Game game;
    while (game.isPlaying()) {
        game.mainMenu();
    }


    return 0;
}
