#include <iostream>
using namespace std;
//#include "viewPortSize.h"

class Player{
    
public:
    char* name; //= new char;
    
    //when you delclare a new player type they all start with £500 to spend
    int* money = new int;
    
    //a bias/strategy variable - this could be char/int
    char* bias;
    
    //ranking
    int ranking;
    
    
    
    Player(){
        cout<<"player constructor called"<<endl;
        *money = 500;
        ranking = 0;
    }
    ~Player(){
        cout<<"player destructor called"<<endl;
        delete money;
//         delete[] bias;
    //   delete[] name;
    }
    
    //methods:
    
    //for making play decision
    //if odds are better than x then bet by y
    //return amound y to add to the running por
    
    
    //for updating player ranking
    void updateRanking(){
    }
    
    int getMoney(){
        return *money;
    }
    
    void updateMoney(int amount){
        *money += amount;
    }
    
    virtual void playerSays(){
        cout<<name<<": ";
    }
};

class PlayerWorf : public Player{
public:
    PlayerWorf(){
        cout<<"worf constructor called"<<endl;
    name = "Worf";
    bias = "cautious";
    
    }
    ~PlayerWorf(){
        cout<<"worf destructor called"<<endl;
       // delete name;
      //  delete[] bias;
        
    }
};

int main(){
    
    //declare the players
    PlayerWorf worf;
    worf.updateMoney(100);
    
    cout<<worf.getMoney()<<endl;
    worf.ranking = 3;
    cout<<worf.ranking<<endl;
    
    worf.playerSays();
    
}