#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
    string description;
     int health;
     int speed;

public:
    void setHealth(int);
    int getHealth();
    void setDesc(string);
    string getDesc();
    void setSpeed(int);
    int getSpeed();

    friend class ZorkUL;

    Character(string description);
	string shortDescription();
    Character();


};

#endif /*CHARACTER_H_*/
