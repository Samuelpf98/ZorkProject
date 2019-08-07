#include <iostream>

using namespace std;
#include "ZorkUL.h"

/*Win Condition is visiting every room
 *Lose Condition is running out of Stamina
 *
 *
*/


ZorkUL::ZorkUL() {
    createPlayer();
    createRooms();

}


void ZorkUL::createRooms()  {


    aPtr = new Room("a");

    bPtr = new Room("b");
        bPtr->addItem(new Item("piece two", 3, 33));
    cPtr = new Room("c");

    dPtr = new Room("d");

    ePtr = new Room("e");
        ePtr->addItem(new Item("piece one", 1, 11));
    fPtr = new Room("f");
    gPtr = new Room("g");

    hPtr = new Room("h");
    hPtr->addItem(new Item("piece three", 4, 44));
    iPtr = new Room("i");
    iPtr->addItem(new Item("piece four", 2, 22));
    sPtr = new Room("s");


//             (N, E, S, W)
    aPtr->setExits(fPtr, bPtr, dPtr, cPtr);
    bPtr->setExits(NULL, NULL, NULL, aPtr);
    cPtr->setExits(NULL, aPtr, NULL, NULL);
    dPtr->setExits(aPtr, ePtr, sPtr, iPtr);
    ePtr->setExits(NULL, NULL, NULL, dPtr);
    fPtr->setExits(NULL, gPtr, aPtr, hPtr);
    gPtr->setExits(NULL, NULL, NULL, fPtr);
    hPtr->setExits(NULL, fPtr, NULL, NULL);
    iPtr->setExits(NULL, dPtr, NULL, NULL);
    sPtr->setExits(dPtr, NULL, NULL, NULL);
        currentRoom = aPtr;



}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    //createCharacter();
    printWelcome();


    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        //finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

string ZorkUL::printWelcome() {
    string welcome = "\n";
    welcome += "You are a nameless Hero, trapped in a Dungeon.\n\n";
    welcome += "Find the pieces of the key to escape, before your Stamina or Health is gone\n\n";
    welcome += currentRoom->longDescription()+"\n";
    return welcome;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
string ZorkUL::processCommand(Command command) {
    string output ="";

    if (command.isUnknown()) {
         output = "invalid input\n\n";
        return output;
}

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        map();
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);
    else if(commandWord.compare("teleport")==0)
    {

       teleport();
       }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        output = "incomplete input";
        return output;
        }
        else
         if (command.hasSecondWord()) {

        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 ){
            output+= "\n\nitem is not in room" ;
        return output;
         }else{
            output = "\nItem " + command.getSecondWord()+" has been added to your Inventory";
            this->Player1->addItems(currentRoom->getItem());
           // for(int i=0;i<this->Player1->invLength();i++){
            //    this->Inventory
            //}
            //output = "item is in room";
            //output+= "\nindex number " + location;
            output+="\n";
            this->Inventory += "\n"+command.getSecondWord();
            itemsGot++;


            output+= currentRoom->longDescription() +"\n\n";
        }}
    }
}
/*
    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return empty; /**signal to quit
    }
    return empty;
}
*/


/** COMMANDS **/
void ZorkUL::printHelp()
{
    cout<< "valid inputs are" << endl;
    parser.showCommands();

}



void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("\n\nNo room in that Direction. \n");
    else
    {
        string go;
        currentRoom = nextRoom;
        go="\n\n"+ currentRoom->longDescription()+"\n\n";
       //go+= ""+ this->getPlayer().setStamina(Player1->getStamina()-10);


        return go;
    }
}

string ZorkUL::teleport(){

    string teleport = "\nTeleporting...\n";

   int random = rand()%10;
    Room* rooms[]={aPtr, bPtr, cPtr, dPtr, ePtr, fPtr, gPtr, hPtr, iPtr, sPtr};
    currentRoom = rooms[random];


    teleport+= currentRoom->longDescription()+"\n";
    return teleport;
}

string ZorkUL::map(){
    string map;
    map+= "\n";
    map +="[h] --- [f] --- [g]\n";
    map +="            |         \n";
    map +="            |         \n";
    map +="[c] --- [a] --- [b]\n" ;
    map +="            |         \n";
    map +="            |         \n";
    map +="[i] --- [d] --- [e]\n";
    map +="           |         \n";
    map +="           |         \n";
    map +="         [s]        \n";

    return map;
}

void ZorkUL::createPlayer(){
    Player1 = new Player("Nameless Hero");
    Player1->health=100;
    Player1->stamina=160;
    Player1->setSpeed(3);

    Goblin = new Enemy("Goblin");
    Goblin->powlvl=1;
    Goblin->health=10;
    Goblin->setdamage(1);
    Goblin->setSpeed(4);
    Orc = new Enemy("Orc");
    Orc->powlvl=2;
    Orc->health=15;
    Orc->setdamage(2);
    Orc->setSpeed(2);
    Ogre= new Enemy("Ogre");
    Ogre->powlvl=3;
    Ogre->health=20;
    Ogre->setdamage(3);
    Ogre->setSpeed(1);



}

int ZorkUL::getPlayerHealth(){
    return this->Player1->health;
}

int ZorkUL::getPlayerStamina(){
    return this->Player1->stamina;
}


QString ZorkUL::getText(){
    return this->text;
}

bool ZorkUL::checkRoom(string item){
    if(this->currentRoom->isItemInRoom(item)>0){
        return true;
    }else{
        return false;
    }
}

void ZorkUL::setText(QString newText){
    this->text=newText;
}

void ZorkUL::playerTravel(){
    this->Player1->stamina=(Player1->stamina-10);

}

/*string ZorkUL::damageTaken(){
    int random = rand()%13;
    this->Player1->health = (Player1->health-random);
    string output = "You have lost ";
    output+=to_string(random);
    output+=" health during your travels.\n";
    return output;
}
*/

template<class T>
T Big(T x, T y){
    return (x>y)?x:y;
}

Player operator+(Player p1, Enemy e1){

    int totallos =0;



    while(p1.getHealth()>0&&e1.getHealth()>0)
    {

        if(p1.getSpeed()==Big(p1.getSpeed(), e1.getSpeed())){
            int randomH = rand()%8;
            e1.setHealth(e1.getHealth()-randomH);
             int randomE = rand()%3;
             randomE+=e1.getlvl();
             e1.setdamage(randomE);
             p1.setHealth(p1.getHealth()-e1.getdamage());

        }
        else{
            int randomE = rand()%3;
            randomE+=e1.getlvl();
            e1.setdamage(randomE);
            p1.setHealth(p1.getHealth()-e1.getdamage());
            int randomH = rand()%8;
            e1.setHealth(e1.getHealth()-randomH);

        }




    }
        return p1;


    }

string ZorkUL::fight(){

    string output ="\nYou entered no combat on your travels.\n";
    int enemyr = rand()%6;
    int startHealth = this->Player1->getHealth();
    if(enemyr==1){
        this->enemy = Goblin;
    }
    else if(enemyr==2){
        this->enemy = Orc;
    }
    else if(enemyr==3){
        this->enemy = Ogre;
    }
    else{
        return output;
    }

    *Player1 = *Player1+*enemy;

    output = "\n Your Hero encountered a "+enemy->getDesc()+ ". You lost ";
    output+= to_string(startHealth-this->Player1->getHealth());
    output+= " health during your fight. \n";

    return output;

}

/*string ZorkUL::fight(){


    string output ="\nYou entered no combat on your travels.\n";
    int enemyr = rand()%6;
    if(enemyr==1){
        enemy = Goblin;
    }
    else if(enemyr==2){
        enemy = Orc;
    }
    else if(enemyr==3){
        enemy = Ogre;
    }
    else{
        return output;
    }
    int totallos =0;

    while(this->Player1->health>0&&enemy->health>0)
    {
    int randomH = rand()%8;
    enemy->health-=randomH;
    int randomE = (rand()%3);
    randomE+=enemy->powlvl;
    enemy->damage=randomE;
    this->Player1->health-=randomE;
    totallos+=randomE;
    }
    if(this->Player1->health>0){
        output = "\n Your Hero encountered a "+enemy->description+ ". You lost ";
        output+= to_string(totallos);
        output+= " health during your fight. \n";
    }
        else if (enemy->health>0) {
            output= "You died";

        }
    return output;

    }

*/

 void ZorkUL::gameCheck(){
        if(this->Player1->getStamina()==0){
            emit this->gameOver();
        }
        else if(this->Player1->getHealth()<=0){
            emit this->gameOver();
        }
        else if(this->itemsGot==4){
            emit this->gameWin();
        }
    }

 string ZorkUL::getCurRoom(){
     return this->currentRoom->getDesc();
 }
