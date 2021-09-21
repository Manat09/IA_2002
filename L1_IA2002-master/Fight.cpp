#include "Fight.h"//include Fight header file
#include "Game.h"

extern int countChoices;

Fight::Fight() {

}
//func. that check can we fight or not
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
//func. where we will fight with enemy
void Fight::startFight(Character character, Enemy enemy){
    cout<<"You have encountered "<<enemy.getName()<<endl;
    while ( character.getHp() > 0 && enemy.getHp() > 0 ){
        //we will fight while we or enemy has HP
        cout<<"Hitting Enemy: ";
        cout<<enemy.getHp()<<" - "<<(character.getAtk() + character.getItem(0).getAtk())<<endl;
        enemy.setHp( enemy.getHp() - (character.getAtk() + character.getItem(0).getAtk()) );
        Sleep(800);//0.8 seconds stop
        if (aliveCheck(character, enemy)){
            break;
        }

        cout<<"Enemy Hitting: ";
        cout<<character.getHp() << " - " << enemy.getAtk()<<endl;
        character.setHp( character.getHp() - enemy.getAtk() );
        Sleep(800);//0.8 seconds stop
        if (aliveCheck(character, enemy)){
            break;
        }

    }
    countChoices++;
    //endFight(character, true);
};
//this func will work after our fight
void Fight::endFight(Character character, bool win){
    Game game;
    //if we will not win
    //we call startMenu func
    if ( win == false){
        cout<<"Your HP is "<<character.getHp()<<"/"<<character.getMaxHp()<<endl;
        cout<<"Game is Over"<<endl;
        character.setHp(1);
        game.startMenu();
    }//if we will win
    //we wil get these words, and will get new items
    else{
        cout<<"/////////////////////////////////////"<<endl;
        cout<<"Enemy is dead! You are alive..."<<endl;
        cout<<"Your HP is "<<character.getHp()<<"/"<<character.getMaxHp()<<endl;
        cout<<"/////////////////////////////////////"<<endl;
        character.gainExp(10);
        character.gainGold(10);

        vector<Item> Items;

        Items.push_back(Item("Axe", 4, "Weapon"));
        Items.push_back(Item("Helm", 3, "Armor"));
        Items.push_back(Item("Sword", 5, "Weapon"));
        Item newItem = Item(Items.at(rand()%3));
        character.lootItem(newItem);
        cout<<"Your have loted:"<<newItem.getName()<<endl;
        cout<<"/////////////////////////////////////"<<endl;


        game.exploreMenu();
    }
};


