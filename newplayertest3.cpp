#include <iostream>
#include <random>
using namespace std;

//initalise variables to be used in the class operations
string dealer;
//initial values for vars:
int numPlayers = 5; //the number of players is 5
int turnNumber = 0; //the initial turn number = 0
int moneyInThePot = 0; //there is 0 money in the pot


class Card{
public:
    int suit;
    int number;
    string suitName;
    string numberName;
    string suitArray[4] = {"Hearts","Clubs","Diamonds","Spades"};
    string numberArray[52] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    Card(){}
    Card(int suit, int number){
        this->suit = suit;
        this->number = number;
        suitName = suitArray[suit];
        numberName = numberArray[number];
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

class Deck{
public:
Card cardsInTheDeck[52];
int numberOfCardsInDeck = 52;
public:
    Deck(){
        int numberOfSuits = 4;
        int numberOfNumbers = 13;
        int indexInPack = 0;
        
        //declare all the cards in the deck when the deck constuctor is called
        for(int s = 0; s < numberOfSuits; s++){
            for(int n = 0; n < numberOfNumbers; n++){
                cardsInTheDeck[indexInPack] = Card(s,n);
                indexInPack++;
  //               cout<<"index in pack = "<<indexInPack<<endl;
  //               cout<<"suiut: = "<<s<<", "<<"number = "<<n<<endl;
            }
        }
    }
    ~Deck(){
        cout<<"deck destructor called"<<endl;
        for(int i = 0; i < 52; i++){
   //         delete cardsInTheDeck[i];
        }
    }
    void shuffle(){
        Card tempArray[numberOfCardsInDeck];
        int orderArray[numberOfCardsInDeck];
        int indexArray[numberOfCardsInDeck];
        int rand;
        int cardsRemaining = numberOfCardsInDeck;
        
        //make an indexArray of numbers 0 - (numberOfCardsInDeck-1) ie (0 - 51)
        for (int i = 0; i<numberOfCardsInDeck; i++){
            indexArray[i] = i;
        }
        
        for (int i = 0; i<numberOfCardsInDeck; i++){
            //pick a random card (number between 0 and (numberOfCardsInDeck-1)
            rand = randomInt(0,cardsRemaining-1);
            //put the chosen rand into the indeArray
            orderArray[i] = indexArray[rand];
            //move the entries from the indexArray along to remove chosen rand
            for (int i = rand; i < cardsRemaining; i++ ){
                indexArray[i] = indexArray[i+1];
            }
            //shorten indexArray
            cardsRemaining--;
          //  orderArray[cardsRemaining];
        }
//         //check:
//         for(int i = 0; i<numberOfCardsInDeck; i++){
//             cout<<orderArray[i]<<" "<<flush;
//         }
            
        //copy cards in cardsInTheDeck to a new temporary array in the ordering from orderArray            
        for (int i = 0 ; i< numberOfCardsInDeck; i++){
            int location = orderArray[i];
       
            //fill the tempArray with the cards in the deck at the new location
            tempArray[i] = cardsInTheDeck[location];
        }
            
        //update cardsInTheDeck from the tempArray
        for(int i = 0; i < numberOfCardsInDeck; i++){
            cardsInTheDeck[i] = tempArray[i];
            cout<<cardsInTheDeck[i].numberName<<" of "<<cardsInTheDeck[i].suitName<<".  "<<flush;
        }
        cout<<endl<<dealer<<" shuffles the cards."<<endl;
    }
};


class Player{
private:
    //only the player is allowed to know what cards they have
    Card cardsInHand[2]; 
    
public:
    string name;
    int numberOfCardsInHand;
    double money;
    //create an array containing all the visible cards
    Card cardsVisible[];
    int totalCardsVisible;
    int cardsUnseen;
 
    Player(){
        money = 500; //players start with 500 money
        numberOfCardsInHand = 0;
    }
    virtual void says(){
        cout<<name<<": "<<flush;
    }
    double getMoney(){
        return this->money;
    }
    void addMoney(double money){
        this->money += money;
    }
    void checkCards(){
        //this is for ease of debugging
        for (int i = 0; i < numberOfCardsInHand; i++){
            cout<<name<<" "<<cardsInHand[i].numberName<< " "<<cardsInHand[i].suitName<<endl ;
        }
    }
    void setCardsInHand(Card c, int position){
        cardsInHand[position] = c;
    }
    void getVisibleCards(int numberOfCardsOnTheTable, Card cardsOnTheTable[]){
        
        //set the cards visible and cards unseen vars
        totalCardsVisible = numberOfCardsInHand + numberOfCardsOnTheTable;
        cardsUnseen = 52 - totalCardsVisible; //note the other players cards are ignored
        
        //fill cardsVisible array with with cards in the hand and on the table
        for(int i = 0; i < numberOfCardsInHand; i++){
            cardsVisible[i] = cardsInHand[i];
        }
        for (int i = 0; i < numberOfCardsOnTheTable; i++){
            cardsVisible[numberOfCardsInHand + i] = cardsOnTheTable[i];
        }
        //check:
        cout<<name<<"'s cards visible: "<<endl;
        for (int i =0; i< totalCardsVisible; i++){
            cout<<cardsVisible[i].numberName<<" of "<<cardsVisible[i].suitName<<endl;
        }
    }
    
    double calcOdds(int numberOfCardsNeededToMakeAHand, int numberOfOuts, int cardsUnseen){
        double odds = 1;
        for (int i = 0; i < numberOfCardsNeededToMakeAHand; i++){
          odds *=  numberOfOuts/cardsUnseen;
          numberOfOuts--;
          cardsUnseen--; //this is the local cardsUnseen var
        }
        return odds;
    }
    
    //YOU NEED TO PRODUCE THE METHODS FOR GETTING THE OUTS IN THESE
    //FLUSH IS DONE BUT NOT TESTED
    //STUFF WILL NEED TO BE COMMENTED OUT FOR TESTING 
    //I LOVE YOU 
    //YOU CAN DO IT! JUST STAY FOCUSED AND TRY!
    //GOOD ENOUGH IS GOOD ENOUGH SO JUST GET ON WITH IT.
    //IT MIGHT EVEN BE FUN 
    
    double straightFlushOdds(){}
    double fourOAKOdds(){}
    double fullHouseOdds(){}
    double flushOdds(){
            //flush: //not the most efficient code but it works (this sentiment for everything)
        int suitTally = 0;
        int highestSuitTally = 0;
        for(int i = 0; i < totalCardsVisible; i++){
            for (int j = 0; j < totalCardsVisible; j++){
                if (cardsVisible[i].suit == cardsVisible[j].suit){
                suitTally++;
                }
            }
            if(suitTally > highestSuitTally){
                highestSuitTally = suitTally;
            } 
        }
        int numberOfCardsNeededToMakeAFlush = 5 - highestSuitTally;
        int numberOfFlushOuts = 13 - highestSuitTally;
            
        return calcOdds(numberOfCardsNeededToMakeAFlush, numberOfFlushOuts, cardsUnseen);
    }
    double straightOdds(){}
    double threeOAKOdds(){}
    double twoPairOdds(){}
    double pairOdds(){}
    
    string makeDecision(double moneyInThePot, int minimumBet){
       double oddsOfWinningHands[8]; //straight flush, 4 of a kind, full house, flush,straight, 3 of a kind, 2 pair, pair
       string decisionForEachHand[8];
       
       oddsOfWinningHands[0] = straightFlushOdds();
       oddsOfWinningHands[1] = fourOAKOdds();
       oddsOfWinningHands[2] = fullHouseOdds();
       oddsOfWinningHands[3] = flushOdds();
       oddsOfWinningHands[4] = straightOdds();
       oddsOfWinningHands[5] = threeOAKOdds();
       oddsOfWinningHands[6] = twoPairOdds();
       oddsOfWinningHands[7] = pairOdds();
       
       //work out odds offered by the ratio of money in the pot to the minimum Bet
       double blah = moneyInThePot + minimumBet;
       double oddsOffered = minimumBet / blah;
       
       for (int i = 0; i < 8; i++){
        if (oddsOfWinningHands[i] - oddsOffered >=  raiseThreshold){
           decisionForEachHand[i] = "Raise!";
            
        }
        else if (oddsOfWinningHands - oddsOffered >=  matchThreshold){
            decisionForEachHand[i] = "MatchBet";
        }
            decisionForEachHand[i] = "Fold:("
    }
    
    //YOU NEED TO FIX THIS - YOU HAVE THE CHANCE OF GETTING A HAND BUT HAVING A PAIR IS NOT THE SAME AS HAVING A WINNING HAND.
   
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

// void anteRound(Player* playerArray[], int anteAmount, Player* human){
//     for (int i = 0; i <numPlayers; i++){
//      if (playerArray[i] != human){
//         playerArray[i]->addMoney(-anteAmount);
//         moneyInThePot += anteAmount;
//         cout<<playerArray[i]->name<<"'s money is now:"<< playerArray[i]->getMoney() <<endl;
//         }
//         else {
//             cout<<dealer<<": How much money do you want to put in for the ante?"<<endl;
//             int anteUpdate;
//             cin>>anteUpdate;
//             while(anteUpdate<anteAmount){
//                 cout<<"You have to put more than the current ante."<<endl;
//                 cin>>anteUpdate;
//             }
//             anteAmount = anteUpdate;
//             playerArray[i]->addMoney(-anteAmount);
//         moneyInThePot += anteAmount;
//         }
//     
//     }
// }

void bettingRound(){
    int bettingAmount = 0;
    
}

void dealCardsToPlayers(int numberOfCardsToBeDealt, Player** playerArray, Deck *d){
    int deckCounter = 0;
       for (int c = 0; c < numberOfCardsToBeDealt; c++){
        for (int n = 0; n < numPlayers; n++){
            
            //how many cards is the player holding? -ie what position of the cardsInHand array should be updated?
            int position = playerArray[n]->numberOfCardsInHand;
            
            //what is the location of the top (unplayed) card on the deck?
            int topCardLocation = d->numberOfCardsInDeck-1;
            //what is the topCard?
            Card topCard = d->cardsInTheDeck[topCardLocation];
            //copy the top card from the deck into the players hand
            playerArray[n]->setCardsInHand(topCard, position);
            
            //update the numbers of cards in different places
            d->numberOfCardsInDeck--;
            playerArray[n]->numberOfCardsInHand++;
        }
    }
}

void dealCardsToTable(int numberOfCardsToBeDealt, Card cardsOnTheTable[], Deck *d, int* numberOfCardsOnTheTable){
    //get the starting position for cardsInTheTable array (ie how many cards are already on the table?)
    const int startingPos = *numberOfCardsOnTheTable;
    for (int i = 0; i < numberOfCardsToBeDealt; i++){
        //what is the location of the top (unplayed) card on the deck?
        int topCardLocation = d->numberOfCardsInDeck-1;
        //copy the cards from the top of the deck to the cardsOnTheTable
        cardsOnTheTable[startingPos + i] = d->cardsInTheDeck[topCardLocation];
        //update position numbers
        (*numberOfCardsOnTheTable)++;
        d->numberOfCardsInDeck--;
    }
    
    //print the cards on the table
    cout<<"Cards on the table: " <<endl;
    for (int i = 0; i< *numberOfCardsOnTheTable;i++){
        cout<<cardsOnTheTable[i].numberName<<" of "<<cardsOnTheTable[i].suitName<<endl;
    }
}

// void isWinningHand(Card cardsVisible[], int totalCardsVisible){
//     for (int t = 0; t < totalCardsVisible; t++){
//         //is the same suite?
//     }
// //}

int main(){
    int numberOfCardsOnTheTable = 0;
    Card cardsOnTheTable[5];
    
  // Worf worf;
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
    dealer = playerArray[dealerNum]->name;
    
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
    
    //shuffle the deck
    d.shuffle();
    
    //check:
//    cout<<"check"<< d.cardsInTheDeck[0].suit<<" "<<d.cardsInTheDeck[0].number<<endl;
    
    //put in the ante
    cout<<dealer<<": Place your ante now. The minimum ante is 10."<<endl;
    //for each of the players offer the opportunity to put in 10 
    //can add additional gameplay dynamics here if time
  //  anteRound(playerArray, 10, human);
    
    
    //deal the pre-flop cards
    //allocate 2 of the cards from cards in the deck to each of the players and the table
     dealCardsToPlayers(2, playerArray, &d);
    
     //check:
//     for (int i = 0; i < numPlayers; i++){
//         playerArray[i]->checkCards();
//     }
    
    //for each of the players in the players array,
    //make decision between "check, bet or fold"
    for (int i = 0; i < numPlayers; i++){
  //      playerArray[i]->makeDecision();
    }
    
    //check
    worf->getVisibleCards(numberOfCardsOnTheTable, d.numberOfCardsInDeck, cardsOnTheTable);
    
    
    //deal 3 cards to the table
    dealCardsToTable(3, cardsOnTheTable, &d, &numberOfCardsOnTheTable);
    
    //check
    worf->getVisibleCards(numberOfCardsOnTheTable, d.numberOfCardsInDeck, cardsOnTheTable);
    
    
    
}

//questions - do you only have to delete stuff in the destructor when you declare things in the heap - Blah* b = new Blah(). what anbout declaring classes themselves in the heap?? 

//stack and heap - declaring class Deck as stack? /not as Deck* d = new Deck() but can still access when not in class anymore, and changes stay... so what is going on with the memory?

//do you need to delete any array or just pointer arrays in the destructor?

//functions that use previously undeclared variables - been passing them as input. is this ok? is there a best practise for this?
