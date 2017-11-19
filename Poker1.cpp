#include <iostream>
using namespace std;
#include "viewPortSize.h"

class Player{
    
    char* name;
    
    //when you delclare a new player type they all start with £500 to spend
    int money = 500;
    
    //a bias/strategy variable - this could be char/int
    char* bias;
    
    //ranking
    int ranking = 0;
    
    Player(){
    }
    ~Player(){
        delete[] bias;
        delete[] name;
    }
    
    //methods:
    
    //for making play decision
    //if odds are better than x then bet by y
    //return amound y to add to the running por
    
    
    //for updating player ranking
    void updateRanking(){
    }
    
    
};

class Worf : public Player{
    Worf(){
    name = "Worf";
    bias = "cautious";
    
    }
    ~Word(){
        
    }
    }
};

int main(){
    
    //declare the players
    Player Worf;
    
}