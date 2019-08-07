#ifndef ZORKUL_H_
#define ZORKUL_H_

#include <string>
#include "Character.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <time.h>
#include<QPushButton>
#include "player.h"
#include "enemy.h"
using namespace std;
#include<QObject>

class ZorkUL: public QObject {

    Q_OBJECT
private:
    Room *currentRoom, *aPtr, *bPtr, *cPtr, *dPtr, *ePtr, *fPtr, *gPtr, *hPtr, *iPtr, *sPtr;
    Player *Player1;
    Enemy *Goblin, *Orc, *Ogre, *enemy;
    Parser parser;
    QString text;


    void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();


    //void gameCheck();

public:



    ZorkUL();
    void play();
    string go(string direction);
    string teleport();
    void createRooms();
    string map();
    string printWelcome();
    void createPlayer();
    int getPlayerHealth();
    int getPlayerStamina();
    void setText(QString);
    QString getText();
    bool checkRoom(string);
    string processCommand(Command command);
    string Inventory;
    void playerTravel();
    void gameCheck();
    int itemsGot=0;
    int printGot();
    string damageTaken();
    string getCurRoom();




     string fight();


signals:
  void gameWin();
  void gameOver();
};
#endif /*ZORKUL_H_*/
