
    
    void calculateOdds(int numberOfCardsOnTheTable, int numberOfCardsInDeck, Card cardsOnTheTable[]){
        
        int totalCardsVisible = numberOfCardsInHand + numberOfCardsOnTheTable;
        
        int cardsUnseen = 52 - totalCardsVisible; //note the other players cards are ignored
        
        //create an array containing all the visible cards
        Card cardsVisible[totalCardsVisible];
        //fill it with cards in the hand
        for(int i = 0; i < numberOfCardsInHand; i++){
            cardsVisible[i] = cardsInHand[i];
        }
        //fill it with cards on the table
        for (int i = 0; i < numberOfCardsOnTheTable; i++){
            cardsVisible[numberOfCardsInHand + i] = cardsOnTheTable[i];
        }
        //check:
        cout<<name<<"'s cards visible: "<<endl;
        for (int i =0; i< totalCardsVisible; i++){
            cout<<cardsVisible[i].numberName<<" of "<<cardsVisible[i].suitName<<endl;
        }
        
//         //orderCards
//         for (int i = 0 ; i < totalCardsVisible; i++){
//             for (int j = 0; j < totalCardsVisible; j++){
//                if (cardsVisible[i].number<)  
//             }
//            
//         }

        //calculate outs needed for each winning hand
        //"outs" are the the cards left in the deck that would produce a winning hand when combined with the players visible cards:
        
        //flush
        //not the most efficient code but it works
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
        int numberOfCardsNotGood = cardsUnseen - numberOfFlushOuts;
        double odds = 1;
        for (int i = 0; i < numberOfCardsNeededToMakeAFlush; i++){
          odds *=  numberOfFlushOuts/cardsUnseen;
          numberOfFlushOuts--;
          cardsUnseen--;
          
        }
        
        
       
    }