#include <iostream>
#include <string>
#include "Credit.h"

int getSumOfDigits(int num) {
	int sum{ 0 };
	for (int i = 0; num > 0 ; i++) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

bool startsWith(const std::string cardNumber, const std::string prefix) {
	for (int i = 0; i < prefix.size(); i++) {
		bool isMatch{ true };
		if (cardNumber[i] == prefix[i]) { continue; }
		else { 
			isMatch = false;
			return isMatch; 
		}
	}
	return true;
};

bool hasValidPrefix(std::string cardNumber) {
	for (int i = 0; i < Constants::validPrefixes.size() ; i++ ) {
		bool isValid = startsWith(cardNumber, Constants::validPrefixes[i]);
		if (isValid) {
			return isValid;
		}
	}
	return false;
}

int sumOddDigitsRightToLeft(std::string cardNumber) {
	int sum = 0;
	for (int i = cardNumber.size()-1; i >= 0; i -= 2) {
		sum += static_cast<int>(cardNumber[i]) + Constants::ASCIICharToInt;
	}
	return sum;
}

//// Add up the even-place digits from right to left
//// - param 1: a string to represent the cardNumber
//// - return: the sum of the (even-place digits * 2) from right to left
//// in the card number (step 1, part 1 & 2).
//// Special rule: multi digit #'s need to be converted by adding
//// their digits together before being added into the sequence.
//// Eg: "34567" returns 11. ((6*2 = 12, converted to 1+2 = 3) + (4*2)) equals 11
//// hint: make use of getSumOfDigits()
//int sumEvenDigitsRightToLeft(std::string cardNumber) {
//	int sum = 0;
//	std::cout << "~~~~~~~~~~~number to sum: " << cardNumber << "\n";
//	for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
//		int digit = static_cast<int>(cardNumber[i]) + Constants::ASCIICharToInt;
//		std::cout << "~~~~~~digit: " << digit << "\n";
//		digit *= 2;
//		std::cout << "Doubled digit: " << digit << "\n";
//		while (digit >= 10) {
//			std::cout << "entered while >10\n";
//			digit = getSumOfDigits(digit);
//			std::cout << "summed double digit: " << digit << "\n";
//		}
//		std::cout << "sum pre-digit: " << sum << "\n";
//		sum += digit;
//		std::cout << "sum post-digit: " << sum << "\n";
//	}
//	return sum;
//}
int sumEvenDigitsRightToLeft(std::string cardNumber) {
	int sum = 0;
	for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
		int digit = (cardNumber[i]) - '0';
		digit *= 2;
		while (digit >= 10) {
			digit = getSumOfDigits(digit);
		}
		sum += digit;
	}
	return sum;
}

//
//// Determine if a card # is valid. Valid if:
//// - between 13 & 16 digits
//// - has a valid prefix
//// - sum of digits according to formula results in a number
//// evenly divisible by 10
//// This is the "workhorse" function that co - ordinates
//// all the others.
//// - param 1: a string to represent the cardNumber
//// - return: true if the card number is valid (false otherwise)
bool isCardValid(std::string cardNumber) {
	//std::cout << "numsize: " << cardNumber.size() << "\n";
	if (cardNumber.size() < 13 || cardNumber.size() > 16) { return false; }
	if (! hasValidPrefix(cardNumber)) { return false; }

	int oddSum{ sumOddDigitsRightToLeft(cardNumber) };
	int evenSum{ sumEvenDigitsRightToLeft(cardNumber) };
	int cardSum = oddSum + evenSum;
	if (cardSum % 10 == 0) { return true; }
	else { return false; }
}

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