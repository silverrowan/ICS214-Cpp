#ifndef CARDS_H
#define CARDS_H

#include <array>

enum class Suit { clubs, diamonds, hearts, spades };
enum class Rank { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

namespace Constants {
    constexpr int CARD_COUNT{ 52 };
    constexpr int NUM_RANKS{ 13 };
    constexpr int NUM_SUITS{ 4 };
}

/// <summary>
/// Pick a random card from the deck (represented by an int between 0-52)
/// </summary>
/// <param name="deck">array of the deck (at each index are the cards)</param>
/// <param name="deckSize">the size of the deck, or active portion</param>
/// <returns>int between 0 - deckSize, the deck position (index) of the card</returns>
int pickRandomCard( int deckSize );

/// <summary>
/// builds the deck array
/// Internal function, not in header file.
/// </summary>
/// <returns>int[], the deck array</returns>
std::array<int, Constants::CARD_COUNT> makeDeck();

// Get the rank of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Rank of the card index given. 
Rank getRank(int index);
std::string getRankString(Rank rank);

// Get the suit of a specific card index 
// - param 1: an int representing the card index 
// - return: an enum representing the Suit of the card index given. 
Suit getSuit(int index);

std::string getSuitString(Suit suit);

// A function to assess whether all elements in a boolean array are true 
// You can use this function to determine whether all suits have been picked. 
// - param 1: an array of boolean values(decide if it should be const or not) 
// - param 2: ? do we need any other parameters here to make this work? You decide. 
// - return: a bool : true if ALL the elements in param 1 are true, false otherwise. 
bool allArrayElementsAreTrue(std::array<bool, 4> suitsPicked);

// This is the function that does all the work behind solving the problem (including 
// sending output to the console). 
// This function should create/use an array of Boolean values (all initially false)  
// to represent the suits that have been picked.   
// It should make use of allArrayElementsAreTrue() to test if all suits have been  
// picked. 
// - param 1: a bool called “verbose” (meaning wordy) that defaults to true.  
//            If verbose is true, generate output cards picked & the pick count. 
// - return: an int representing the number of card picks it takes to cover 4 suits. 
int getPickCountNeededForFourSuits(bool verbose, bool withReplacement, std::array<int, Constants::CARD_COUNT>& deck);

void getPickEachCard();

#endif