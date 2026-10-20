#ifndef MAINMENU_H
#define MAINMENU_H

// The MainMenu (.h & .cpp) file contains the function declarations used to 
// Present a main menu which allows a user to view, add, and remove employees.
// The list of employees is implemented with a linked list, and most of the
// processing functions get passed a pointer to the first element of the 
// list (Employee* pHead).

#include <string>

// A command set of operations that can be used with our Menu.
enum class Command{ viewEmployees, addEmployee, removeEmployee, removeAllEmployees, exit, invalid };

// a struct to represent an Employee (each instance forms a node of a linked list
// used to store employees.
struct Employee {
	int id;
	std::string name;
	Employee* pNext;
};

// A struct used to return multiple return values from the getNodeInfo() function.
// getNodeInfo() traverses the list looking for a target node (and its parent node).
// NodeInfo contains info needed to facilitate node insertion & deletion in the list.
struct NodeInfo {
	Employee* pNode;	// a pointer to the "target" node.
	Employee* pParent;	// a pointer to the node prior to pNode (nullptr if node is at the front)
};

// Clear any characters from the (keyboard) input buffer
void ignoreLine();

// Read and return an int from the console. Keep trying until an int is returned.
int getIntFromUser();

// display the main menu
void displayMainMenu();

// fetch and return a menu command from user input
Command getMenuCommand();

// Given a Command, this will determine the appropriate function to call.
// - param 1: (given) a pointer to the front of the list of employees (passed by reference)
// - param 2: a Command (enum) representing the action to be taken.
void handleMenuInput(Employee*& pHead, Command command);

// Outputs a list of all employees to the console.
// in the format: id: x name:  abc
// If the list is empty, prints "empty list.\n" 
// -param 1: (given) a pointer to an Employee struct (representing the front 
//			 of the list of employees.
// return: nothing
void viewEmployees(Employee* pHead);

// Creates a new employee struct on the heap.
// Generates id from an auto-increment
// - param 1: a string - the employee's name.
// - return: a pointer to the dynamically allocated Employee struct 
Employee* createEmployee(const std::string name);

// Create a new employee node, then add it to the front of the list
// - param 1: a pointer to the front of the list of employees (passed
//            by reference)
// - param 2: a string - the employee's name.
// - return: nothing
void addNewEmployee(Employee*& pHead, std::string name);

// Search through the list for a node with the given id.  
// - param 1: (given) a pointer to an Employee struct (representing the front  
//			  of the list of employees
// - param 2: an int (the id of the employee we're searching for). 
// - return: a NodeInfo struct. It contains a pointer to the node that matches  
//			 the id passed in and a pointer to that node's parent. 
//           If node not found, pointers inside NodeInfo should both be nullptr.
//           If node is first in the list, NodeInfo.pParent should be nullptr.
NodeInfo getNodeInfo(Employee* pHead, const int findId);

// Removes an employee node with the given id from the list. And outputs a
// message to the console. Deallocates the memory used for teh employee struct
// - param 1: (given) a pointer to the front of the list of employees (passed by reference)
// - param 2: an int (the id of the employee we're searching for). 
// - return: nothing
void removeEmployee(Employee*& pHead, int id);

// Removes every employee in the list and deallocates the memory
// - param 1: a reference to a pointer pointing to the head of the list
// - return: nothing
void removeAllEmployees(Employee*& pHead);
#endif
