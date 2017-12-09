double calcOdds(int numberOfCardsNeededToCompleteHand, int numberOfOuts, int cardsUnseen){
    
    void makeDecision(int numberOfCardsOnTheTable, Card cardsOnTheTable[]){
        
        double oddsOfWinningHands[8]; //straight flush, 4 of a kind, full house, flush,straight, 3 of a kind, 2 pair, pair

        
        //calculate the odds of each of the winning hands
        //straightflush:
        
        //4 of a kind:
        
        //full house: 
        
       
        //straight: 
        
        //3 of a kind: 
        
        //2 pair, pair
    }
    
   
    
    void calculateFlushOuts(){
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
     //   int numberOfCardsNotGood = cardsUnseen - numberOfFlushOuts;
        calcOdds(numberOfCardsNeededToMakeAFlush, numberOfFlushOuts, cardsUnseen )
    }
    
    