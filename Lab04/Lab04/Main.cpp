#include <iostream>
#include <string>
#include "Credit.h"

int main() {
	std::cout << startsWith("123", "21") << "\n";
	std::cout << startsWith("1000153", "0") << "\n";
	std::cout << startsWith("1", "2") << "\n";
	std::cout << startsWith("456", "4") << "\n";
	std::cout << startsWith("456", "45") << "\n";
}