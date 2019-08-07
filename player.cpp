#include "player.h"

Player::Player(string description){
    this->setDesc(description);
}

    void Player::setStamina(int stamina){
        this->stamina = stamina;
    }

    int Player::getStamina(){
        return stamina;
    }

    int Player::invLength()
    {
        return this->itemsInCharacter.size();
    }


    void Player::addItems(Item item) {
        itemsInCharacter.push_back(item);
    }

    void Player::addItems(Item *item) {
       itemsInCharacter.push_back(*item);
        delete item;
    }

    string Player::longDescription()
    {
      string ret = this->getDesc();
      ret += "\n Item list:\n";
      for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t"+ (*i).getLongDescription() + "\n";
      return ret;
    }



