#include "enemy.h"



Enemy::Enemy(string description){
    this->setDesc(description);
}

int Enemy::getdamage(){
    return this->damage;
}

void Enemy::setdamage(int damage){
    this->damage=damage;
}

int Enemy::getlvl(){
    return this->powlvl;
}
