#include <iostream>
#include <string>
#include "Credit.h"

int main() {
// Testing get sum of digits
	//std::cout << getSumOfDigits(456) << "\n";
	//std::cout << getSumOfDigits(1000153) << "\n";
	//std::cout << getSumOfDigits(1) << "\n";
	//std::cout << getSumOfDigits(456) << "\n";
	//std::cout << getSumOfDigits(456) << "\n";
// Testing Starts With
	//std::cout << startsWith("123", "21") << "\n";
	//std::cout << startsWith("1000153", "0") << "\n";
	//std::cout << startsWith("1", "2") << "\n";
	//std::cout << startsWith("456", "4") << "\n";
	//std::cout << startsWith("456", "45") << "\n";
// Testing has valid prefix - options are (in const array): { "4", "5", "37", "6" };
	//std::cout << hasValidPrefix("556") << "\n"; //t
	//std::cout << hasValidPrefix("1000153") << "\n";
	//std::cout << hasValidPrefix("1") << "\n";
	//std::cout << hasValidPrefix("37") << "\n"; //t
	//std::cout << hasValidPrefix("3345") << "\n";
	//std::cout << hasValidPrefix("3790") << "\n"; //t
	//std::cout << hasValidPrefix("456") << "\n"; //t
	//std::cout << hasValidPrefix("378") << "\n"; //t
	//std::cout << hasValidPrefix("9378") << "\n";
// Testing summOddRTL & even
	//std::cout << sumEvenDigitsRightToLeft("556") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("1000153") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("1") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("37") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("3345") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("3790") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("456") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("378") << "\n";
	//std::cout << sumEvenDigitsRightToLeft("9378") << "\n";
//// Testing summOddRTL & even
//	std::cout << isCardValid("6331101999990016") << "\n";
//	std::cout << isCardValid("37535050500000") << "\n";
//	std::cout << isCardValid("378282246310005") << "\n";
//	std::cout << isCardValid("371449635398431") << "\n";
//	std::cout << isCardValid("5060606505000000") << "\n";
//	std::cout << isCardValid("4388576018410707") << "\n";
//	std::cout << isCardValid("40100000000000") << "\n";
//	std::cout << isCardValid("4388576018410707") << "\n";
//	std::cout << isCardValid("378282246310005") << "\n";
//
//	std::cout << isCardValid("4012888888881881") << "\n";
//	std::cout << isCardValid("36545050500000") << "\n";
//	std::cout << isCardValid("37144963539843100") << "\n";
//	std::cout << isCardValid("1010101515000000") << "\n";
//	std::cout << isCardValid("8348576018410707") << "\n";
//	std::cout << isCardValid("401000000000000000") << "\n";
//	std::cout << isCardValid("401000000000") << "\n";
//	std::cout << isCardValid("4388576018402626") << "\n";
//	std::cout << isCardValid("4388576018410708") << "\n";
//	std::cout << isCardValid("378282246320005") << "\n";
//	std::cout << isCardValid("1042888888881881") << "\n";		

std::string ccNumber{ };
std::cout << "Enter a credit card number (to check if valid): ";
std::cin >> ccNumber;

bool isValid{ isCardValid(ccNumber) };
}