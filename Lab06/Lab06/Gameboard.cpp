#include <iomanip>
#include "Gameboard.h"

	//static const int MAX_X = 10;		// gameboard x dimension
	//static const int MAX_Y = 19;		// gameboard y dimension
	//static const int EMPTY_BLOCK = -1;	// contents of an empty block


	// the gameboard - a grid of X and Y offsets.  
	//  ([0][0] is top left, [MAX_Y-1][MAX_X-1] is bottom right) 
	//int grid[MAX_Y][MAX_X];

// constructor - empty() the grid
Gameboard::Gameboard() : grid{  } {}

// fill the board with EMPTY_BLOCK 
//   (iterate through each rowIndex and fillRow() with EMPTY_BLOCK))
// - params: none
// - return: nothing
void Gameboard::empty() {
	for (int i = 0; i < Gameboard::MAX_Y; i++) {
		for (int k = 0; k < Gameboard::MAX_X; i++) {
		}
	}
}

// print the grid contents to the console (for debugging purposes)
//   use std::setw(2) to space the contents out 
//   (google it, you'll need to #include <iomanip>).
//   If the content == EMPTY_BLOCK, print a '.', otherwise print the content.
// - params: none
// - return: nothing
//void printToConsole();