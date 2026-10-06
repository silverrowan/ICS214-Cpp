#include <iostream>
#include "Cards.h"


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

// Pick a random card from the deck (represented by an int between 0-52)  
// - params: none 
// - return: an int between 0 - 51 
int pickRandomCard(std::array<int, Constants::CARD_COUNT> deck, int deckSize ) {
    int deckIndex = pickRandomNumberInRange(0, deckSize-1);
    return deck[deckIndex];
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
// - param 2: ? do we need any other here to make this work? You decide. 
// - return: a bool : true if ALL the elements in param 1 are true, false otherwise. 
bool allArrayElementsAreTrue(std::array<bool, 4> suitsPicked) {
    //for (bool suit : suitsPicked) { //slightly slower
    //    if (suit == false) { return false; } }
    if (suitsPicked[0] == false || suitsPicked[1] == false || suitsPicked[2] == false || suitsPicked[3] == false) { return false; }
    else { return true; }
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
int getPickCountNeededForFourSuits(bool verbose, bool withReplacement) {
    int activeDeck { Constants::CARD_COUNT };
    std::array<int, Constants::CARD_COUNT> deck = makeDeck();
    int cardsPulled = 0;
        //if (withReplacement == true) {
            std::array<bool, 4> suitsPicked = { false, false, false, false };
            while (true) {
                int cardIndex = pickRandomCard(deck, activeDeck);
                Suit suit = getSuit(cardIndex);

                cardsPulled += 1;

                if (suitsPicked[(int)(suit)] == false) {
                    suitsPicked[(int)(suit)] = true;
                    if (verbose == true) {
                        Rank rank = getRank(cardIndex);
                        std::string rankString = getRankString(rank);
                        std::string suitString = getSuitString(suit);
                        std::cout << rankString << " of " << suitString << "\n";
                    }
                    if (withReplacement == false) {
                        //swap picked card with card at end of the array and shrink active deck size, to cut off that (now) end card
                        std::swap(deck[cardIndex], deck[activeDeck]);
                        activeDeck--;
                    }
                    if (allArrayElementsAreTrue(suitsPicked) == true) { 
                        break; 
                    }
                }
                else {
                    if (withReplacement == false) {
                        //swap picked card with card at end of the array and shrink active deck size, to cut off that (now) end card
                        std::swap(deck[cardIndex], deck[activeDeck]);
                        activeDeck--;
                    }
                }
            }
        if (verbose == true) {
            std::cout << "Number of picks: " << cardsPulled << "\n\n";
        }
        return cardsPulled;
        }
    //else { // without replacement

    //    std::array<Card, 52> drawDeck{};
    //    for ( Suit suit :  )
    //}

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