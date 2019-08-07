#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include "Character.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;
class Player: public Character
{
public:
    Player(string description);
    void addItems(Item);
   void addItems(Item*);
    void setStamina(int);
    int getStamina();
    int invLength();
    string longDescription();

    friend class ZorkUL;

private:
    vector < Item> itemsInCharacter;
    int stamina;
};

#endif // PLAYER_H
