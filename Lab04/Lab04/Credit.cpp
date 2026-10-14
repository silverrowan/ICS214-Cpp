#include <iostream>
#include <string>
#include "Credit.h"

int getSumOfDigits(int num) {
	int sum{ 0 };
	for (int i{ 0 }; num > 0; i++) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

bool startsWith(const std::string& cardNumber, const std::string& prefix) {
	for (int i{ 0 }; i < prefix.size(); i++) {
		bool isMatch{ true };
		if (cardNumber[i] == prefix[i]) { continue; }
		else { 
			return false; 
		}
	}
	return true;
};

bool hasValidPrefix(const std::string& cardNumber) {
	for (int i{ 0 }; i < Constants::validPrefixes.size(); i++) {
		bool isValid{ startsWith(cardNumber, Constants::validPrefixes[i]) };
		if (isValid) {
			return isValid;
		}
	}
	return false;
}

int sumOddDigitsRightToLeft(const std::string& cardNumber) {
	int sum{ 0 };
	for (int i = cardNumber.size() - 1; i >= 0; i -= 2) { // using i = ... rather than i{ static_cast....} as want the casting to occur, and the line is already getting long
		sum += (cardNumber[i]) - '0';
	}
	return sum;
}

int sumEvenDigitsRightToLeft(const std::string& cardNumber) {
	int sum{ 0 };
	for (int i = cardNumber.size() - 2; i >= 0; i -= 2) { // for i = ... see comment in function above
		int digit{ (cardNumber[i]) - '0' };
		digit *= 2;
		while (digit >= 10) {
			digit = getSumOfDigits(digit);
		}
		sum += digit;
	}
	return sum;
}

bool isCardValid(const std::string& cardNumber) {
	if (cardNumber.size() < Constants::MIN_CC_LENGTH || cardNumber.size() > Constants::MAX_CC_LENGTH) { return false; }
	if (! hasValidPrefix(cardNumber)) { return false; }

	int oddSum{ sumOddDigitsRightToLeft(cardNumber) };
	int evenSum{ sumEvenDigitsRightToLeft(cardNumber) };
	int cardSum{ oddSum + evenSum };
	if (cardSum % 10 == 0) { return true; }
	else { return false; }
}