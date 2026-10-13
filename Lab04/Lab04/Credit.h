#ifndef CREDIT_H
#define CREDIT_H
#include <string>
#include <array>

namespace Constants {
	inline const std::array< std::string, 4 > validPrefixes = { "4", "5", "37", "6" };
	const int ASCIICharToInt = -48;
}

/// <summary>
/// Given an int, return the sum of its individual digits
/// </summary>
/// <param name="num">int - a number to analyze (eg: 123)</param>
/// <returns>int representing the sum of digits (eg: 123 returns 6)</returns>
int getSumOfDigits(int num);

/// <summary>
/// Determine if a given card number starts with a given prefix
/// Hint: research how the string.substr() function works. (used [] access instead)
/// </summary>
/// <param name="cardNumber">string representing the card number</param>
/// <param name="prefix">string representing the prefix</param>
/// <returns>true if cardNumber starts with prefix (false otherwise)</returns>
bool startsWith(std::string cardNumber, std::string prefix);

/// <summary>
/// Determine if a cardNum has a valid prefix.
/// </summary>
/// <param name="cardNumber">string representing the cardNumber</param>
/// <returns>true if cardNumber in one of the valid starting strings (false otherwise)</returns>
bool hasValidPrefix(std::string cardNumber);

/// <summary>
/// Add up the odd-place digits from right to left
/// </summary>
/// <param name="cardNumber">string to represent the cardNumber</param>
/// <returns>sum of odd-place digits from right to left Eg: "34567" returns 15. (7+5+3)</returns>
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