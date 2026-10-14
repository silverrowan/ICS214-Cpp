#include <iostream>
#include <string>
#include <fstream>
#include "Credit.h"

// TODO
// [x] work as expected
// [x] pass by ref as appropriate
//		- are strings of length 13-16 reasonably large enough to be worth the extra complexity?
//		- assuming yes because of assnment and b/c ref is less effor than pointer & address
// [x] const ref as appropriate
// [x] uniform initialized variables
// [x] constants replace 'magic nums'

int main() {
	std::cout << "------------------------------\n";
	std::string inputFilename{ "cards.txt" };
	std::ifstream fin;
	fin.open(inputFilename);
	if (fin.is_open()) {
		std::string ccNumber;
		int validCount{ 0 };
		while (fin >> ccNumber) {
			bool isValid{ isCardValid(ccNumber) };
			if (isValid) { validCount++; }
			std::cout << ccNumber << " valid:" << isValid << "\n";
		}
		std::cout << "------------------------------\n";
		std::cout << "valid cards: " << validCount;
		fin.close();
	}
	else {
		std::cout << "Error: could not open file: \"" << inputFilename << "\"" << std::endl;
		exit(1);
	}
}