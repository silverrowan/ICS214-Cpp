#include <iostream>
#include <string>
#include <fstream>
#include "Credit.h"

int main() {
	std::cout << "------------------------------\n";
	std::string inputFilename = "cards.txt";
	std::ifstream fin;
	fin.open(inputFilename);
	if (fin.is_open()) {
		std::string ccNumber;
		int validCount{ 0 };
		while (fin >> ccNumber) {
			//std::string ccNumber{ };
			bool isValid{ isCardValid(ccNumber) };
			if (isValid) { validCount++; }
			std::cout << ccNumber << " valid:" << isValid << "\n";
			//std::cin >> ccNumber;
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