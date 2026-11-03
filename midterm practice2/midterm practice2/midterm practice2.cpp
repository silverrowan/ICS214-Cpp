// midterm practice2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

	// Topics: 
	// - pass by address
	// - dereferencing pointers
	// ============================================================
	// Question [5 pts]
	// [2] Write a function called swapByAddress()
	// - param 1: a pointer to a char
	// - param 2: a pointer to a char
	//   return: nothing. [1pt] The original arguments should be modified
	// [2 pt] Make changes to the use example below to show what would need to 
	//        change to make this work.
	// 
	// Use example:
	//   see testQ2() below
	// -------------------------------------------------------------

void swapByAddress() {}

void testQ2() {
	std::cout << "testQ2()----------\n";
	//int arr[] = { 1,2,3 };
	//std::cout << arr;

	//char arr2[] = "Chris";
	//std::cout.operator<<(arr2);




	char c1{ 'a' };
	char c2{ 'b' };
	std::cout << &c1 << "\n";
	std::cout << c1 << " " << static_cast<const void*>(& c1) << "\n";
	//swapByAddress(c1, c2);
	//std::cout << c1 << c2 << '\n';  // output: ba 
}

int main()
{
	testQ2();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
