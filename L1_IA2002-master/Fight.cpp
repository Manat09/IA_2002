#include "Fight.h"

extern int countChoices;

Fight::Fight() {

}

void Fight::startFight(Character character, Enemy enemy){
    cout<<"You have encountered "<<enemy.getName();
    countChoices++;
    //endFight(character, true);
};

void endFight(Character character, bool win){

    /*
    Item item("Wooden Sword", 1, "Weapon");
    Item item2("Plate", 2, "Armor");
    Item item3("Slippers", 3, "Legs");

    character.lootItem(item);
    //character.setItem(item);
    character.gainExp(10);
     */
};


