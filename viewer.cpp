#include <iostream>
using namespace std;


//make the graphics

//#include "viewPortSize.h" <-this code probably wont help, you found it at
//https://answers.unrealengine.com/questions/94342/how-to-get-current-screen-sizeresolution.html

//start screen
//draw outline?
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
//each player chooses between "stick" "fold" or "raise"
//this is decision is based on a function f(trueChances, bias value, int pot){ probably some form of multiplication }
//if isRaise == false
    //if the function decision returns below a certain threshold the player will choose to "stick"
        //stick returns no money into the pot
    //if decision returns above a threshold the player will choose to "raise" by int raiseAmount:
    //isRaise == true
    //pot += raiseAmount;
    //turnNumber++;

//starting from the dealer + turnNumber
//decision() is run for the next player
    //pot is updated
    //new trueOdds calculated
    //

    



void updateGraphics(){
    
}

int main(){
    return 0;
}