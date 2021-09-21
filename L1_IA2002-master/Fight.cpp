#include "Fight.h"
#include "Game.h"

extern int countChoices;

Fight::Fight() {

}

bool Fight::aliveCheck(Character character, Enemy enemy){
    if ( enemy.getHp() <= 0 || character.getHp() <= 0){
        if ( enemy.getHp() <= 0 ){
            endFight(character, true);
        }
        else {
            endFight(character, false);
        }
        return true;
    }

    return false;
};

void Fight::startFight(Character character, Enemy enemy){
    cout<<"You have encountered "<<enemy.getName()<<endl;
    while ( character.getHp() > 0 && enemy.getHp() > 0 ){

        cout<<"Hitting Enemy: ";
        cout<<enemy.getHp()<<" - "<<(character.getAtk() + character.getItem(0).getAtk())<<endl;
        enemy.setHp( enemy.getHp() - (character.getAtk() + character.getItem(0).getAtk()) );

        if (aliveCheck(character, enemy)){
            break;
        }

        cout<<"Enemy Hitting: ";
        cout<<character.getHp() << " - " << enemy.getAtk()<<endl;
        character.setHp( character.getHp() - enemy.getAtk() );

        if (aliveCheck(character, enemy)){
            break;
        }

    }
    countChoices++;
    //endFight(character, true);
};

void Fight::endFight(Character character, bool win){
    Game game;
    if ( win == false){
        cout<<"Your HP is "<<character.getHp()<<"/"<<character.getMaxHp()<<endl;
        cout<<"Game is Over"<<endl;
        character.setHp(1);
        game.startMenu();
    }
    else{
        cout<<"/////////////////////////////////////"<<endl;
        cout<<"Enemy is dead! You are alive..."<<endl;
        cout<<"Your HP is "<<character.getHp()<<"/"<<character.getMaxHp()<<endl;
        cout<<"/////////////////////////////////////"<<endl;
        character.gainExp(10);
        character.gainGold(10);
        game.exploreMenu(character);
    }
    /*
    Item item("Wooden Sword", 1, "Weapon");
    Item item2("Plate", 2, "Armor");
    Item item3("Slippers", 3, "Legs");

    character.lootItem(item);
    //character.setItem(item);
    character.gainExp(10);
     */
};


