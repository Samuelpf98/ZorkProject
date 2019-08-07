#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "player.h"
#include <string>
#include <vector>
using std::vector;



class Enemy: public Character
{
public:
    Enemy(string description);
    int getdamage();
    void setdamage(int damage);
    int getlvl();
    void setlvl();


    friend class ZorkUL;

private:
    int damage;
    int dodge;
    int powlvl;
};

#endif // ENEMY_H
