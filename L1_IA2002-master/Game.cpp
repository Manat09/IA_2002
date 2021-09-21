#include "Game.h"

extern int countChoices;

Character character;
Game::Game(){
    //start
    choice = 0;
    playing = true;

};

//our main script
//where we can choose our way
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
            //here we write name of character
            cout<<"Enter your name: "<< endl;
            string name;
            cin>>name;
            //and here creating character
            character.createCharacter(name);
            startMenu();
            break;}
        default: break;
    }
}
//also here we have chooses
void Game::startMenu() {
    cout<<"Greetings, "<<character.getName()<<endl;
//we can explore or check our stats
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
                exploreMenu();
                break;
            }
            case 2: {

                cout << character.toStringStats() << endl;
                break;
            }
            default:
                cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n"<<"There is no that choice!"<<"\n"<<
                    "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n";
                startMenu();
                //Item item2("Secret sword", 10, "Weapon");
                //Item item2("Plate", 10, "Armor");
                //character.lootItem(item2);
                break;
        }
    }
}

void Game::exploreMenu() {
    cout<<"Your HP is "<<character.getHp()<<"/"<<character.getMaxHp()<<endl;
    cout<<"0: Give Up (Tou will lose all Exp, Items and golds)"<<endl;
    cout<<"1: Enter The Dungeon ->"<<endl;
    cout<<"2: Buy treatment potion (It costs 10 golds) ->"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    switch (choice){
        case 0: {
            mainMenu();
            break;
        }//here some enemies that have hp, maxHp and atk
        case 1: {
            Fight fight;
            Enemy enemy[]={Enemy("Slime", 1, 1, 1),
                           Enemy("Troll", 5, 5, 1),
                           Enemy("Goblin", 8, 8, 1),
                           Enemy("Hob-Goblin", 13, 13, 2),
                           Enemy("Diablo", 20, 20, 7)};
            int ind = rand()%4;
            cout<<"Your enemy is "<<enemy[ind].getName()<<endl;
            cout<<"HP: "<<enemy[ind].getHp()<<" | ATK: "<<enemy[ind].getAtk()<<endl;
            cout<<"1: Fight"<<endl;
            cout<<"2: GiveUp (You will gain -1 HP)"<<endl;
            cout<<"Choice: ";
            cin>>choice;
            switch (choice) {
                case 1: { fight.startFight(character, enemy[ind]); }
                case 2: { character.setHp(character.getHp()-1); }
                default: {
                    //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n"<<"There is no that choice!"<<"\n"<<
                    //"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n";
                }
            }
            break;
        }
        case 2: {
            if(character.getGold() > 10){
                character.setGold(character.getGold() - 10 );
                character.setHp( character.getMaxHp() );
                cout<<"Bless you!"<<endl;
            }
            else{
                cout<<"You don't have enough gold. Give up or try your lucky."<<endl;
                startMenu();
            }
        }
        default: {
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n"<<"There is no that choice!"<<"\n"<<
                "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<"\n";
            exploreMenu();
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
