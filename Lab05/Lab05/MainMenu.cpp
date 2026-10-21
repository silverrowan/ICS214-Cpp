#include <iostream>
#include "MainMenu.h"
#include "MemoryDebug.h"

// why is it setup to have 2 switch statements+enum? (getMenu... handleMenu...)

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntFromUser() {
	while (true) {
		int guess;
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cin.clear();
			ignoreLine();
			std::cerr << "Invalid input. Input must be a valid int.  Please try again.\n";
		}
		else
		{
			ignoreLine();
			return guess;
		}
	}
}

void displayMainMenu()
{
	std::cout << "\n";
	std::cout << "--- MENU ---\n";
	std::cout << "1) View Employees\n";
	std::cout << "2) Add Employee\n";
	std::cout << "3) Remove Employee\n";
	std::cout << "4) Remove All Employees\n";
	std::cout << "0) Exit\n";
	std::cout << "-------------\n";
	std::cout << "Select:";
}

Command getMenuCommand() {
	// read user input
	int input{ -1 };  // default 
	std::cin >> input;
	if (std::cin.fail()) {
		std::cin.clear();	// clear the failure
		input = -1;			// indicate an error
	}
	ignoreLine();	// ignore any extra input

	Command command = Command::invalid;	// default
	// match input with specific commands
	switch (input) {
	case 1: command = Command::viewEmployees; break;
	case 2: command = Command::addEmployee; break;
	case 3: command = Command::removeEmployee; break;
	case 4: command = Command::removeAllEmployees; break;
	case 0: command = Command::exit; break;
	}
	return command;
	//I *am* wondering *why* the menu cmd has been broken down into 2
	//switch statements....
}

void handleMenuInput(Employee*& pHead, const Command command)
{
	switch (command)
	{
	case Command::viewEmployees:
		std::cout << ">> View Employees:\n";
		viewEmployees(pHead);
		break;
	case Command::addEmployee: {
		std::cout << ">> Add Employee:\n";
		std::cout << "Enter name:";
		std::string name;
		std::getline(std::cin, name);
		addNewEmployee(pHead, name);
	}
		break;
	case Command::removeEmployee:
		std::cout << ">> Remove Employee:\n";
		std::cout << "Enter id:";
		removeEmployee(pHead, getIntFromUser());
		break;
	case Command::removeAllEmployees:
		removeAllEmployees(pHead);
		break;
	case Command::exit:
		std::cout << "Exiting\n";
		removeAllEmployees(pHead);
		break;
	default:
		std::cout << "Invalid input.\n";
		break;
	}
}

void viewEmployees(const Employee* pHead){ //its not editing pHead, why is it complaining that pNext = pHead when const pHead?
								// const type* pVar means the CONTENTS of the pointer cant be changed!
								//			pointer itself can be changed still.
								// type* const pVar means the POINTER ITSELF can't be changed
	if (!pHead) {
		std::cout << "empty list.\n";
		return;
	}
	const Employee* pNext{ pHead };
	while (pNext) {
		Employee newEmp{ *pNext };
		std::cout << "Id: " << newEmp.id << " Name: " << newEmp.name << "\n";
		pNext = newEmp.pNext;
	}
}

Employee* createEmployee(const std::string& name) {
	static int employeeCount{ -1 };
	Employee* pNewEmp{ DBG_NEW Employee { ++employeeCount, name, nullptr} };
	return pNewEmp;
}

void addNewEmployee(Employee*& pHead, const std::string& name) {
	Employee* prevPHead{ pHead };
	pHead = createEmployee(name);
	pHead->pNext = prevPHead;
}

NodeInfo getNodeInfo(Employee* pHead, const int findId) {
	//					  pNode, pParent
	NodeInfo idNodeInfo{ nullptr, nullptr };

	if (!pHead) {
		return idNodeInfo;
	}
	idNodeInfo.pNode = pHead;
	idNodeInfo.pParent = nullptr;

	while (idNodeInfo.pNode) {
		Employee newEmp{ *idNodeInfo.pNode };
		if (newEmp.id == findId) {
			return idNodeInfo;
		}
		else if (newEmp.pNext) {
			idNodeInfo.pParent = idNodeInfo.pNode;
			idNodeInfo.pNode = newEmp.pNext;
		}
		else {
			idNodeInfo.pNode = nullptr;
			idNodeInfo.pParent = nullptr;
			return idNodeInfo;
		}
	}
}

void removeEmployee(Employee*& pHead, const int id) {
	NodeInfo removeInfo{ getNodeInfo(pHead, id) };
	Employee* pRemoveNode{ removeInfo.pNode };
	if (pRemoveNode) {
		std::cout << "removed id: " << id << "\n";
		Employee* pNextLink{ pRemoveNode->pNext };

		if ((pRemoveNode) == pHead) {
			pHead = pNextLink;
		}
		else {
			Employee* pParentNode{ removeInfo.pParent };
			pParentNode->pNext = pNextLink;
		}
		delete pRemoveNode;
		pRemoveNode = nullptr;
	}
	else {
		std::cout << "Error: employee id: " << id << " not found\n";
		return;
	}
}

void removeAllEmployees(Employee*& pHead) {
	if (pHead) {
		Employee* pRemoveNode{ pHead };
		while (pRemoveNode) {
			Employee* pNext{ pRemoveNode->pNext };
			delete pRemoveNode;
			pRemoveNode = pNext;
			pHead = nullptr;
		}
		std::cout << "Removed all Employees.\n";
	}
	else {
		std::cout << "No employees to remove\n";
	}
}

