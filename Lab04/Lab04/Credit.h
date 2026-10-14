#ifndef CREDIT_H
#define CREDIT_H
#include <string>
#include <array>

namespace Constants {
	inline const std::array< std::string, 4 > validPrefixes = { "4", "5", "37", "6" };
	const int ASCIICharToInt{ -48 };
	const int MIN_CC_LENGTH{ 13 };
	const int MAX_CC_LENGTH{ 16 };
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
bool startsWith(const std::string& cardNumber, const std::string& prefix);

/// <summary>
/// Determine if a cardNum has a valid prefix.
/// </summary>
/// <param name="cardNumber">string representing the cardNumber</param>
/// <returns>true if cardNumber in one of the valid starting strings (false otherwise)</returns>
bool hasValidPrefix(const std::string& cardNumber);

/// <summary>
/// Add up the odd-place digits from right to left
/// </summary>
/// <param name="cardNumber">string to represent the cardNumber</param>
/// <returns>sum of odd-place digits from right to left Eg: "34567" returns 15. (7+5+3)</returns>
int sumOddDigitsRightToLeft(const std::string& cardNumber);

/// <summary>
/// Add up the doubled even-place digits from right to left
/// </summary>
/// <param name="cardNumber">string to represent the cardNumber</param>
/// <returns>int, sum of the (even-place digits * 2) from right to left</returns>
int sumEvenDigitsRightToLeft(const std::string& cardNumber);

/// <summary>
///  Determine if a card # is valid. Valid if:
/// - between 13 & 16 digits
/// - has a valid prefix
/// - sum of digits formula results in a number evenly divisible by 10
/// </summary>
/// <param name="cardNumber">string to represent the cardNumber</param>
/// <returns>true if the card number is valid (false otherwise)</returns>
bool isCardValid(const std::string& cardNumber);

#endif // !CREDIT_H