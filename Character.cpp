#include "Character.h"

Character::Character(){
    this->description= "NPC";
}
Character::Character(string description){
    this->description = description;
}

void Character::setDesc(string description) {
	this->description = description;
}

void Character::setHealth(int health){
    this->health = health;
}

int Character::getHealth(){
    return health;
}

string Character::getDesc(){
    return this->description;
}

int Character::getSpeed(){
    return this->speed;
}

void Character::setSpeed(int speed){
    this->speed =speed;
}



