#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Gameboard.h"
#include "Point.h"
#include "Tetromino.h"

void Gameboard::empty() {
	for (int y = 0; y < Gameboard::MAX_Y; y++) { //row/y
		fillRow(y, Gameboard::EMPTY_BLOCK);
	}
}

// print the grid contents to the console (for debugging purposes)
//   use std::setw(2) to space the contents out 
//   (google it, you'll need to #include <iomanip>).
//   If the content == EMPTY_BLOCK, print a '.', otherwise print the content.
// - params: none
// - return: nothing
void Gameboard::printToConsole() const {
	for (int y = 0; y < Gameboard::MAX_Y; y++) { //row/y
		for (int x = 0; x < Gameboard::MAX_X; x++) { //col/x
			int content{ getContent(x, y) };

			char outChar{};
			if (content == -1) { outChar = '.'; }
			else { outChar = content; }

			std::cout << std::setw(2) << outChar;
		}
		std::cout << '\n';
	}
}


// get the content at a given XY location
// assert the point is valid (use isValidPoint())
// - param 1: an int for X (column)
// - param 2: an int for Y (row)
// - return: an int, the content from the grid at the specified XY
int Gameboard::getContent(int x, int y) const {
	assert(isValidPoint( x, y ) && "coordinates are invalid");

	return grid[y][x]; 
}


void Gameboard::setContent(std::vector<Point> pts, int content) {
	for (int i = 0; i < pts.size(); i++) {
		Point targetPt = pts.at(i);
		Gameboard::setContent(targetPt, content);
	}
}

void Gameboard::setContent(int x, int y, int content) {
	if (isValidPoint(x, y)) {
		grid[y][x] = content;
	}
}

bool Gameboard::isValidPoint(Point pt) const {
	int x = pt.getX();
	int y = pt.getY();

	return Gameboard::isValidPoint(x, y);
}

bool Gameboard::isValidPoint(int x, int y) const {
	if (x > Gameboard::MAX_X || y > Gameboard::MAX_Y || x < 0 || y < 0) {
		return false;
	}
	else { return true; }
}

bool Gameboard::isRowCompleted(int rowIndex) {
	for (int x = 0; x < Gameboard::MAX_X; x++) {
		if (getContent(x, rowIndex) == Gameboard::EMPTY_BLOCK) {
			return false;
		}
	}
	return true;
}

void Gameboard::fillRow(int rowIndex, int content) {
	for (int x = 0; x < Gameboard::MAX_X; x++) { //col/x
		setContent(x, rowIndex, content);
	}
}

void Gameboard::removeRow(int rowIndex) {
	assert(isRowCompleted( rowIndex ) && "Incomplete Row");

	for (int row = rowIndex; row > 0; row--) {
		copyRowIntoRow(row - 1, row);
	}
	fillRow(0, EMPTY_BLOCK);
}