#include "Game.h"
//Inventory with 3 best items
//Fight system
//Enemy class

void ToThink(){
    string thoughts[5] = { "I haven't eaten in almost 8 hours.",
                           "I want to sleep.",
                           "However, it is cold today.",
                           "I will overcome enemies and become the strongest.",
                           "I ought to go to my parents somehow."};
    srand( time( 0 ) );
    for(size_t i = 0; i<=20; i++){
        this_thread::sleep_for(chrono::milliseconds(rand()%20000+10000));
        cout<<"\n*****************\n"<<thoughts[rand()%4]<<"\n*****************\n";

    }
}

int countChoices;
int main() {
    thread th (ToThink);
    th.detach();

    Game game;
    while (game.isPlaying()) {
        game.mainMenu();
    }


    return 0;
}
