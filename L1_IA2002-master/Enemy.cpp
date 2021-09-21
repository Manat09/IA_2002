#include "Enemy.h"//include Enemy header file
//use constructor
Enemy::Enemy(string name,int HP, int maxHP,int atk) {
    this->name = name;
    this->HP = HP;
    this->maxHP = maxHP;
    this->atk = atk;
}
//and these setters and getters
const string &Enemy::getName() const {
    return name;
}

int Enemy::getHp() const {
    return HP;
}

int Enemy::getMaxHp() const {
    return maxHP;
}

int Enemy::getAtk() const {
    return atk;
}

void Enemy::setHp(int hp) {
    HP = hp;
}
