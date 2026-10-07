#ifndef CREDIT_H
#define CREDIT_H
#include <string>

// Given an int, return the sum of its individual digits
// hint: an easy way to parse an int into digits is by isolating
// the ‘ones’ column (via %10), and reducing the number (via /10)
// in a loop until it is 0.
// - params: int - a number to analyze (eg: 123)
// - return an int representing the sum of digits (eg: 123 returns 6)
int getSumOfDigits(int num);

// Determine if a given card number starts with a given prefix
// Hint: research how the string.substr() function works.
// - param 1: a string representing the card number
// - param 2: a string representing the prefix
// - return: true if cardNumber starts with prefix (false otherwise)
bool startsWith(std::string cardNumber, std::string prefix);

// Determine if a cardNum has a valid prefix.
// - param 1: a string representing the cardNumber
// - return: true if cardNumber starts with string literals:
// "4", "5", "6" or "37" (false otherwise)
// You could use string literals in this function, but it would
// much be cleaner to create a "Constants" namespace in your header
// file and create a const array of strings there (validPrefixes).
// that you can reference in this function.
// hint: you can make use of startsWith() in this function.
bool hasValidPrefix(std::string cardNumber);

// Add up the odd-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of odd-place digits from right to left in the card
// number (step 1, part 3).
// Eg: "34567" returns 15. (7+5+3)
int sumOddDigitsRightToLeft(std::string cardNumber);

// Add up the even-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of the (even-place digits * 2) from right to left
// in the card number (step 1, part 1 & 2).
// Special rule: multi digit #'s need to be converted by adding
// their digits together before being added into the sequence.
// Eg: "34567" returns 11. ((6*2 = 12, converted to 1+2 = 3) + (4*2)) equals 11
// hint: make use of getSumOfDigits()
int sumEvenDigitsRightToLeft(std::string cardNumber);

// Determine if a card # is valid. Valid if:
// - between 13 & 16 digits
// - has a valid prefix
// - sum of digits according to formula results in a number
// evenly divisible by 10
// This is the "workhorse" function that co - ordinates
// all the others.
// - param 1: a string to represent the cardNumber
// - return: true if the card number is valid (false otherwise)
bool isCardValid(std::string cardNumber);

//------------------
// checkValid (sum -> %10=0) - overarching controlling function
// doubleEvenRtoLPlaces()
// doubleNumber()
// countDigits()
	// checkSinglePlace ( check if >1 digit)... or may use count =1
// checkPrefix()
	// startsWithPrefix(specific one)
// splitNumber ( change number into array of numbers)
// sumAllPlaces()
// sumOddRtoLPlaces()

#endif // !CREDIT_H