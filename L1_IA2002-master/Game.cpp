#include "Game.h"

extern int countChoices;

Character character;
Game::Game(){
    //start
    choice = 0;
    playing = true;

};


void Game::mainMenu() {
    cout<<"Number of choices: "<<countChoices<<endl;
    cout<<"Main Menu"<< endl;
    cout<<"1: Start"<< endl;
    cout<<"0: Exit"<< endl;

    cout<<"Choice: ";
    cin>>choice; countChoices++;
    switch(choice){
        case 0: {playing = false;
            break;}
        case 1: {
            cout<<"Enter your name: "<< endl;
            string name;
            cin>>name;
            character.createCharacter(name);
            startMenu();
            break;}
        default: break;
    }
}

void Game::startMenu() {
    cout<<"Greetings, "<<character.getName()<<endl;

    while(choice!=0) {
        cout << "Start Menu" << endl;
        cout << "1: Explore" << endl;
        cout << "2: Check stats" << endl;
        cout << "0: Go to main menu" << endl;

        cout << "Choice: ";
        cin >> choice;countChoices++;
        switch (choice) {
            case 0:
                break;
            case 1: {
                Fight fight;
                Enemy enemy("Troll", 5, 5,1);
                fight.startFight(character, enemy);

                break;
            }
            case 2: {

                cout << character.toStringStats() << endl;
                break;
            }
            default:
                //Item item2("Secret sword", 10, "Weapon");
                Item item2("Plate", 10, "Armor");
                character.lootItem(item2);
                break;
        }
    }
}

int Game::getChoice() const
{
    return choice;
}

bool Game::isPlaying() const {
    return playing;
}
