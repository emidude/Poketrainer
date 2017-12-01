#include <iostream>
#include <random>
using namespace std;

class Player{
private:
    double money;
public:
   // const char* name;
    string name;
    Player(){
        money = 0;
    }
    virtual void says(){
        cout<<name<<": "<<flush;
    }
};

class Worf : public Player{
public:
    Worf() {
        this->name = "Worf";
    }
};

class Riker : public Player{
public:
    Riker() {
        this->name = "Riker";
    }
};

class Geordi : public Player{
public:
    Geordi() {
        this->name = "Geordi";
    }
};

class Data : public Player{
public:
    Data() {
        this->name = "Data";
    }
};

class Human : public Player{
public:
    Human(string name)  {
    this->name = name;
    }
};

class Card{
public:
    int suit;
    //string suit?
    int number;
    Card(){}
    Card(int suit, int number){
        this->suit = suit;
        this->number = number;
    }
};

class Deck{
public:
Card* cardsInTheDeck[52];
int numberOfCardsInDeck = 52;
public:
    Deck(){
        int numberOfSuits = 4;
        int numberOfNumbers = 13;
        int indexInPack = 0;
        
        //declare all the cards in the deck when the deck constuctor is called
        for(int s = 0; s < numberOfSuits; s++){
            for(int n = 0; n < numberOfNumbers; n++){
                cardsInTheDeck[indexInPack] = new Card(s,n);
                indexInPack++;
//                 cout<<"index in pack = "<<indexInPack<<endl;
//                 cout<<"suiut = "<<s<<endl;
//                 cout<<"number = "<<n<<endl;
            }
        }
    }
    ~Deck(){
        cout<<"destructor called"<<endl;
        for(int i = 0; i < 52; i++){
            delete cardsInTheDeck[i];
        }
    }
    void shuffle(){
        int tempArray[numberOfCardsInDeck];
        
    }
};

int randomInt(int bottom, int top){
    //returns a random number between bottom and top
    
    //THE CODE BELOW WAS TAKEN DIRECTLY FROM LAB 7 CW SHEET
    //*I DID NOT WRITE ANY OF THE CODE IN THE AREA MARKED BETWEEN COMMENT LINES BELOW*
    ////////////////////////////////////////////
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(bottom, top);
    int random = uniform_dist(e1);
    return random;    
    ////////////////////////////////////////////
}

void reorderArray(int dealerNumIn, int numPlayersIn, Player* playerArrayIn[]){
    
    int numPlayers = numPlayersIn;
    int dealerNum = dealerNumIn;
    
    //make the person "to the dealer's left" be the one who plays first (is the first player in the array)
    if(dealerNum + 1 == numPlayers){
    dealerNum = 0;
    }
    else {
        dealerNum = dealerNum + 1;
    }
    
    //rearrange playerArray to match player order:
    //this rearranges so that dealer is first
    Player* tempArray[dealerNum];
    
//    cout <<"dealerNum = "<<dealerNum<<endl;    
    for(int i = 0; i < dealerNum; i ++){
        tempArray[i] = playerArrayIn[i];
//        cout<< "tempArray[" << i<< "]: "<< tempArray[i]->name<<endl;
    }
 //   cout <<"t1"<<endl;
    for(int i = 0; i < numPlayers - dealerNum; i++){
        playerArrayIn[i] = playerArrayIn[dealerNum + i];
//         cout<< "playerArray1[" << i<< "]: "<< playerArrayIn[i]->name<<endl;
    }
//    cout << "t2"<<endl;
    
    for(int i = numPlayers - dealerNum; i < numPlayers; i++){
        playerArrayIn[i] = tempArray[i - (numPlayers - dealerNum)];
 //       cout<< "playerArray2[" << i<< "]: "<< playerArrayIn[i]->name<<endl;
    }
 //       cout << "t3"<<endl;
    
     //test:
//     for (int i = 0; i < numPlayers; i++){
//         cout<<"playerArray ["<<i<<"]: " << playerArrayIn[i]->name <<endl;
//     }
}



int main(){
    
    //when the game starts:
    int numPlayers = 5; //the number of players is 5
    int turnNumber = 0; //the initial turn number = 0
    int moneyInThePot = 0; //there is 0 money in the pot
    
 //   Worf worf;
    Player *worf = new Worf();
    Player *riker = new Riker();
    Player *geordi = new Geordi();
    Player *data = new Data();
    
    cout<<endl;
    worf->says();
    
    cout<< "Identify yourself player. What is your name?"<<endl;
    cout<< "You: "<<flush;
      
    //input player name to the human class
    string username;
    cin >> username;
    Player *human = new Human(username);
      
    riker->says();
    cout<<"Hello "<<username<< ". Welcome to the poker game."<<endl;
    
    //initialise player array
    Player* playerArray[] = {riker, data, worf, geordi, human};

    //randomly choose who will start the game as the dealer:
    int dealerNum = randomInt(0,4);
    string dealer = playerArray[dealerNum]->name;
    
    cout<< "Tonight, the first one to be the dealer is "<< dealer <<"."<<endl;
    
    //reorder playerArray so that the dealer is first in the array
    reorderArray(dealerNum, numPlayers, playerArray);
    
    cout<<"The order of play shall be: "<<endl;
    for (int i = 0; i < numPlayers; i++){
        cout<<i+1<<": " << playerArray[i]->name <<endl;
    }

    cout<<endl;
    cout<<"Let's begin."<<endl;
    
    //initialise Deck
    Deck d;
    
    cout<<"suit "<<d.cardsInTheDeck[50]->suit<<endl;
    
}

//questions - do you only have to delete stuff in the destructor when you declare things in the heap - Blah* b = new Blah(). what anbout declaring classes themselves in the heap?? 