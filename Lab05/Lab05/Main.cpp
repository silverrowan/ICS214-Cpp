#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "MainMenu.h"
#include "TestSuite.h"

// Set up a pointer for tracking a linked list of Employees
// Display a menu allowing a user various choices, and process those choices
// Clean up any dynamically allocated memory before finishing
int main()
{	
	//bebugging memory leaks code
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// run auto tests
	TestSuite::runTestSuite();

	// a pointer to our linked list of employees.
	int prevEmployeeCount{ 0 };
	Employee* pEmployees = nullptr;

	bool exitMainMenu{ false };		// init to default value
	Command command{ Command::invalid };

	// display the main menu, allow the user to make choices, and handle the input
	do {
		displayMainMenu();
		command = getMenuCommand();
		handleMenuInput(pEmployees, command);
	} while (command != Command::exit);

	return 0;
}
