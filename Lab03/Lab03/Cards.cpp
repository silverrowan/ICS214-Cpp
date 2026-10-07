#include <iostream>
#include "Cards.h"

/// <summary>
/// Picks a random integer between two numbers
/// Internal function, not in header file.
/// </summary>
/// <param name="min">int, minimum value</param>
/// <param name="max">int, maximum value</param>
/// <returns>int, random number</returns>
int pickRandomNumberInRange(int min, int max) // inclusive of min & max
{
    int rangeSize{ max - min + 1 };
    int randomNumber{ min + (rand() % rangeSize) };
    return randomNumber;
}

std::array<int, Constants::CARD_COUNT> makeDeck() {
    std::array<int, Constants::CARD_COUNT> deck = {};
    for (int i = 0; i < Constants::CARD_COUNT; i++) {
        deck[i] = i;
    }
    return deck;
}

//   
// - params: none 
// - return: an int  
int pickRandomCard( int activeDeckSize ) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< has a param <<<<<<<<<<<<<<<<<<<<<<

    return rand() % activeDeckSize;  // [0..51]
   // return pickRandomNumberInRange(0, activeDeckSize-1);
}

// Get the rank of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Rank of the card index given. 
Rank getRank(int index) {
    int rankNum = (index) % Constants::NUM_RANKS;
    return static_cast<Rank>(rankNum);
};

std::string getRankString(Rank rank) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< doesint have description <<<<<<<<<<<<<<<<<<<<<<
    //Rank rank = getRank(index);
    //std::array<std::string, 13> ranks = { "ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king" };
    std::string ranks[] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"}; // <<<<<<<<<<<<<<<<<<<<<<< could move this into the Constants namespace <<<<<<<<<<<<<<<<<<<
    return ranks[ static_cast<int>(rank) ];
}

// Get the suit of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Suit of the card index given. 
Suit getSuit(int index) {
    int suitNum = (index) / Constants::NUM_RANKS;
    return static_cast<Suit>(suitNum);
};

std::string getSuitString(Suit suit) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< doesint have description <<<<<<<<<<<<<<<<<<<<<<
    //Suit suit = getSuit(index);
    std::string suitArray[] = {"clubs", "diamonds", "hearts", "spades"}; // <<<<<<<<<<<<<<<<<<<<<<< could move this into the Constants namespace <<<<<<<<<<<<<<<<<<<
    return suitArray[ static_cast<int>(suit) ];
}

// A function to assess whether all elements in a boolean array are true 
// You can use this function to determine whether all suits have been picked. 
// - param 1: an array of boolean values(decide if it should be const or not) 
// - param 2: ? do we need any other here to make this work? You decide. 
// - return: a bool : true if ALL the elements in param 1 are true, false otherwise. 
bool allArrayElementsAreTrue(std::array<bool, 4> suitsPicked) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< has only one param but describes 2 <<<<<<<<<<<<<<<<<<<<<<
    //for (bool suit : suitsPicked) { //slightly slower
    //    if (suit == false) { return false; } }
    return suitsPicked[0] && suitsPicked[1] && suitsPicked[2] && suitsPicked[3];
   // if (suitsPicked[0] == false || suitsPicked[1] == false || suitsPicked[2] == false || suitsPicked[3] == false) { return false; }
   // else { return true; }
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
int getPickCountNeededForFourSuits(bool verbose, bool withReplacement, std::array<int, Constants::CARD_COUNT>& deck) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< has 4 params <<<<<<<<<<<<<<<<<<<<<<
    int activeDeck { Constants::CARD_COUNT };
    int cardsPulled = 0;
    std::array<bool, 4> suitsPicked = { false, false, false, false };

    while (true) {
        int cardIndex = pickRandomCard( activeDeck);
        int cardValue = deck[cardIndex];
        Suit suit = getSuit(cardValue);

        cardsPulled += 1;

        if (withReplacement == false) {
            //swap picked card with card at end of the array and shrink active deck size, to cut off that (now) end card
            std::swap(deck[cardIndex], deck[activeDeck-1]);
            activeDeck--;
        }

        if (suitsPicked[(int)(suit)] == false) {
            suitsPicked[(int)(suit)] = true;
            if (verbose == true) {
                Rank rank = getRank(cardValue);
                std::string rankString = getRankString(rank);
                std::string suitString = getSuitString(suit);
                std::cout << rankString << " of " << suitString << "\n";
            }

            if (allArrayElementsAreTrue(suitsPicked) == true) { // <<<<<<<<<<<<<<<<<<<<<<<<<<<< could move this up into the while loop <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                break; 
            }
        }
    } //end while loop

    if (verbose == true) {
        std::cout << "Number of picks: " << cardsPulled << "\n\n";
    }
    return cardsPulled;
    }