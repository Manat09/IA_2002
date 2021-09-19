#include "Character.h"


Character::Character() {
    name = "Player";
    HP = 0;
    maxHP = 0;
    Atk = 0;
    level = 0;
    exp= 0;
    //item = Item();
    //Create initial character
}

void Character::createCharacter(string name){
    this->name = name;
    HP = 5;
    maxHP = 5;
    Atk = 1;
    level = 1;
    exp= 0;
}

string Character::toStringStats() {
    string string1;
    string1 = "Name "+getName()+"\n"+"HP "+ to_string(getHp()) + "/"+to_string(getMaxHp())+"\n"+
            +"Atk "+to_string(getAtk())+"\n"+"Level "+to_string(getLevel())+"\n"+"Exp "+to_string(getExp())+"\n";
            //+"Inventory: "+item[0].getName()+" "+ to_string(item[0].getAtk())+"\n";//
    string1=string1+ "Inventory: \n";
    for (int i = 0; i < 3; i++) {
        if (item[i].getName() != "Test") {
            string1 += item[i].getName() + " " + to_string(item[i].getAtk()) + "\n";
        }
    }




    return string1;

}


void Character::gainExp(int exp){
    //this->exp = this->exp +exp;
    setExp(getExp() +exp);
    //cout<<"Exp debug: "+this->exp;
    if (this->exp >= 10*level){
        level++;
        this->exp=0;
        maxHP = maxHP+5;
        HP = maxHP;
        Atk = Atk+1;
    }

}


const string &Character::getName() const {
    return name;
}

int Character::getHp() const {
    return HP;
}

int Character::getMaxHp() const {
    return maxHP;
}

int Character::getAtk() const {
    return Atk;
}

int Character::getLevel() const {
    return level;
}

int Character::getExp() const {
    return exp;
}

void Character::setName(const string &name) {
    Character::name = name;
}

void Character::setHp(int hp) {
    HP = hp;
}

void Character::setMaxHp(int maxHp) {
    maxHP = maxHp;
}

void Character::setAtk(int atk) {
    Atk = atk;
}

void Character::setLevel(int level) {
    Character::level = level;
}

void Character::setExp(int exp) {
    Character::exp = exp;
}

void Character::lootItem(Item itemReceived){//slot 0 weapon, slot 1 armor, slot 2 legs

    int slot;
    if (itemReceived.getCategory()=="Weapon"){
        slot = 0;
    }
    if (itemReceived.getCategory()=="Armor"){
        slot = 1;
    }
    if (itemReceived.getCategory()=="Legs"){
        slot = 2;
    }

    if (item[slot].getAtk()>itemReceived.getAtk()){
        return;
    }
    item[slot] = itemReceived;
};
