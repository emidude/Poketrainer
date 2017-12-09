#include <iostream>
using namespace std;


//defining player classes:
class Player{
public:
  //  const char* name = new char;
    string name;
    int money;
    int bias;
    int ranking;
    Player(){
        money = 500;
        ranking = 0;
        cout<<"player constructor called"<<endl;
    }
    virtual ~Player(){
        cout<<"player destructor caleld"<<endl;
    }
    
    void says(){
        cout<<name<<": ";
    }
    
    const char* getName(){
        return name;
    }
    virtual void setName(const char* name){};
};

class PlayerWorf : public Player{
public:
    PlayerWorf(){
        name = "Worf";
    }
    
};
class PlayerRiker : public Player{
public:
    PlayerRiker(){
        name = "Riker";
    }
};
class PlayerData : public Player{
public:
    PlayerData(){
        name = "Data";
    }
};
class PlayerGeordi : public Player{
public:
    PlayerGeordi(){
        name = "Geordi";
    }
};

class PlayerHuman : public Player{
public:
    PlayerHuman(string name){
        cout<<"human constructor called "<<endl;
        this->name = name;
        cout<<"human name is: "<<this->name<<endl;
        cout<<"input name is: "<<name<<endl;
    }
//        PlayerHuman(){
//         cout<<"human constructor called"<<endl;
//     }
    ~PlayerHuman(){
        cout<<"human destructor caleld"<<endl;
    }
    void setName(string name){
        this->name = name;
    }
    
};

//make the graphics

//#include "viewPortSize.h" <-this code probably wont help, you found it at
//https://answers.unrealengine.com/questions/94342/how-to-get-current-screen-sizeresolution.html

// void welcome(Player* you){
//   
//     char* username;
//         cin>>username;
//         you = new PlayerHuman(username) ;
// }


int main(){
    //start screen
    
    //declare players
    Player* worf = new PlayerWorf();
    Player* riker = new PlayerRiker();
    Player* data = new PlayerData;
    Player* geordi = new PlayerGeordi;
//     Player* playersArray[] = {new PlayerWorf(), new PlayerRiker(), new PlayerData(), new PlayerGeordi(), new PlayerHuman()};
    
    
    
    cout<<"Welcome to the enterprise poker game. What is your name?"<<endl;
    
    string username;
    cin>>username;
    
     PlayerHuman* human = new PlayerHuman(username);
//     
     cout<<human->getName()<<endl;
     cout<<human->name<<endl;
    
    Player* playersArray[] = {worf, riker, data, human, geordi};
    
    int numberOfPlayers = 5;
    for(int i = 0 ; i < numberOfPlayers; i++){
        cout << playersArray[i]->getName() <<endl;
    }
    
    //playersArray[4]->setName(username);
    //cout<<"player name"<<*human->name;
    
//    cout<<"getname"<<(*human).getName()<<endl;
//     cout<<"human says ";
//    (&human)->says();
    
//     PlayerWorf worf2; 
//     PlayerRiker riker2; 
//     PlayerData data2; 
//     PlayerGeordi geordi2; 
//     
//     PlayerHuman human2(username);
//     human2.says();
    
 //    Player* playerArray2[]  = {&worf2, &riker2, &human2};
//     for (int i = 0; i < 3; i++){
//         playerArray2[i].says();
//     }
//     return 0;
}



//draw riker, worf, gordi and data on the sreen 
//introductory information

//start of the game
//int turnNumber = 0;
//one player is randomly allocated dealer role
//initialise dealer order number
//for instance if Riker is selected as the dealer then 
//Riker = 0, "to the left" = down:
    //data      2
    //geordi    3
    //riker     0
    //worf      1

//round one:

//declare money in the pot = 0

//put the ante in
    //remove money from each players money val

//update int pot = sum of total antes

//3 cards on the table 
//each player gets 2 cards of random value between 0 and 52
//once a card has been selected it is removed from the pack
//and the random number interval is now 0 to 51 (ie 1 is removed from int numberOfCardsInTheDeck.

//the cards are "dealt" one at a time to each player? <- actually it is probably not necessary to mirror the action of the cards at this point -order doesnt matter here...

//odds calculator calulates the odds of the players having a winning hand given the cards they can "see" (these should be private)
//you will need a method for displaying this when the human types a command into the box
//upon moving to the next hand there will need to be a method for removing this from the screen...
//  maybe no problem? just call screenDraw method to run the display again

//each player must run the odds calculator and update their trueChances.

//this is followed by game action

//starting from the dealers left
//int decision(){}
//each player chooses between "stick" "fold" "raise" or "match bet"
//this is decision is based on a function f(trueChances, bias value, int pot){ probably some form of multiplication }
//if isRaise == false
    //if the function decision returns below a certain threshold the player will choose to "stick"
        //stick returns no money into the pot
    //if decision returns above a threshold the player will choose to "raise" by int raiseAmount:
    //player.money -= raiseAmount;
    //isRaise == true;
    //pot += raiseAmount;
    //turnNumber++;
    //moneyDue += raiseAmount;

//starting from the dealer + turnNumber
//decision() is run for the next player
    //pot is updated
    //new trueOdds calculated
    //input these into decision
    //if (isRaise == true){ 
    // return either matchbet, raise or fold depending on whether fn returns a number over a particular threshold }


    


/*
void updateGraphics(){
    
}

int main(){
    return 0;
}*/