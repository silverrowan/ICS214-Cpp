#include <iostream>
#include "Cards.h"
#include <array>

int pickRandomNumberInRange(int min, int max) // inclusive of min & max
{
    int rangeSize{ max - min + 1 };
    int randomNumber{ min + (rand() % rangeSize) };
    return randomNumber;
}

// Pick a random card from the deck (represented by an int between 0-52)  
// - params: none 
// - return: an int between 0 - 51 
int pickRandomCard() {
    return pickRandomNumberInRange(0, Constants::CARD_COUNT - 1);
}

// Get the rank of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Rank of the card index given. 
Rank getRank(int index) {
    int rankNum = (index) % Constants::NUM_RANKS;
    return static_cast<Rank>(rankNum);
};

std::string getRankString(Rank rank) {
    //Rank rank = getRank(index);
    std::array<std::string, 13> ranks = { "ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king" };
    return ranks[ static_cast<int>(rank) ];
}

// Get the suit of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Suit of the card index given. 
Suit getSuit(int index) {
    int suitNum = (index) / Constants::NUM_RANKS;
    return static_cast<Suit>(suitNum);
};

std::string getSuitString(Suit suit) {
    //Suit suit = getSuit(index);
    std::array<std::string, 4> suitArray = { "clubs", "diamonds", "hearts", "spades" };
    return suitArray[ static_cast<int>(suit) ];
}

// A function to assess whether all elements in a boolean array are true 
// You can use this function to determine whether all suits have been picked. 
// - param 1: an array of boolean values(decide if it should be const or not) 
// - param 2: ? do we need any other parameters here to make this work? You decide. 
// - return: a bool : true if ALL the elements in param 1 are true, false otherwise. 
bool allArrayElementsAreTrue(std::array<bool, 4> suitsPicked) {
    for (bool suit : suitsPicked) {
        if (suit == false) { return false; }
    }
    return true;
};

// This is the function that does all the work behind solving the problem (including 
// sending output to the console). 
// This function should create/use an array of Boolean values (all initially false)  
// to represent the suits that have been picked.   
// It should make use of allArrayElementsAreTrue() to test if all suits have been  
// picked. 
// - param 1: a bool called “verbose” (meaning wordy) that defaults to true.  
//            If verbose is true, generate output cards picked & the pick count. 
// - return: an int representing the number of card picks it takes to cover 4 suits. 
int getPickCountNeededForFourSuits(bool verbose) {
    std::array<bool, 4> suitsPicked = {false, false, false, false};
    int cardsPulled = 0;
    while (true) {
        int cardIndex = pickRandomCard();

        Rank rank = getRank(cardIndex);
        Suit suit = getSuit(cardIndex);
        std::string rankString = getRankString(rank);
        std::string suitString = getSuitString(suit);

        cardsPulled += 1;

        if (suitsPicked[ (int)(suit) ] == false) {
            suitsPicked[ (int)(suit) ] = true;

            std::cout << rankString << " of " << suitString << "\n";
            if (allArrayElementsAreTrue(suitsPicked) == true) { break; }
        }
        else if (verbose == true) {
            std::cout << rankString << " of " << suitString << "\n";
        }
    }
    std::cout << "Number of picks: " << cardsPulled << "\n\n";
    return cardsPulled;
}

void getPickEachCard() {
    std::array<bool, 4> suitsPicked = { false, false, false, false };
    int cardsPulled = 0;
    for ( int i = 0 ; i < 52 ; i++) {
        //int cardIndex = pickRandomCard();
        int cardIndex = i;

        Rank rank = getRank(cardIndex);
        Suit suit = getSuit(cardIndex);
        std::string rankString = getRankString(rank);
        cardsPulled += 1;

        if (suitsPicked[ (int)(suit) ] == false) {
        suitsPicked[ (int)(suit) ] = true;

        std::string suitString = getSuitString(suit);
        std::cout << rankString << " of " << suitString << "\n";
            if (allArrayElementsAreTrue(suitsPicked) == true) { break; }
        }
    }
    std::cout << "Number of picks: " << cardsPulled << "\n\n";
}