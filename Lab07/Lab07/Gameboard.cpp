#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Gameboard.h"
#include "Point.h"
#include "Tetromino.h"

void Gameboard::empty() {
	for (int y = 0; y <= Gameboard::MAX_Y; y++) { //row/y
		fillRow(y, Gameboard::EMPTY_BLOCK);
	}
}

void Gameboard::printToConsole() const {
	for (int y = 0; y <= MAX_Y; y++) { //row/y
		for (int x = 0; x <= MAX_X; x++) { //col/x
			int content{ getContent(x, y) };

			char outChar{};
			if (content == -1) { outChar = '.'; }
			else { outChar = content; }

			std::cout << std::setw(2) << outChar;
		}
		std::cout << '\n';
	}
}

int Gameboard::getContent(int x, int y) const {
	assert(isValidPoint( x, y ) && "coordinates are invalid");

	return grid[y][x]; 
}


void Gameboard::setContent(std::vector<Point> pts, int content) {
	for (int i = 0; i < pts.size(); i++) {
		Point targetPt = pts.at(i);
		setContent(targetPt, content);
	}
}

void Gameboard::setContent(int x, int y, int content) {
	if (isValidPoint(x, y)) {
		grid[y][x] = content;
	}
}

// Determine if (valid) all points passed in are empty
// *** IMPORTANT: Assume invalid x,y values can be passed to this method.
// Invalid meaning outside the bounds of the grid.
// * ONLY TEST VALID POINTS (use isValidPoint()). Ignore invalid Points.
// Using invalid points to index into the grid would cause undefined behaviour. 
// - param 1: a vector of Points representing locations to test
// - return: true if the content at ALL VALID points is EMPTY_BLOCK, false otherwise
//bool areAllLocsEmpty(std::vector<Point> pts) const;

// Remove all completed rows from the board
//   use getCompletedRowIndices() and removeRows() 
// - params: none
// - return: the count of completed rows removed
//int removeCompletedRows();

bool Gameboard::isValidPoint(int x, int y) const {
	return (x <= Gameboard::MAX_X && x >= 0 && isValidRow(y) );
}

bool Gameboard::isRowCompleted(int rowIndex) {
	assert(isValidRow(rowIndex) && "Not a valid gamboard row");
	for (int x = 0; x <= Gameboard::MAX_X; x++) {
		if (getContent(x, rowIndex) == Gameboard::EMPTY_BLOCK) {
			return false;
		}
	}
	return true;
}

void Gameboard::fillRow(int rowIndex, int content) {
	for (int x = 0; x <= MAX_X; x++) { //col/x
		setContent(x, rowIndex, content);
	}
}

std::vector<int> Gameboard::getCompletedRowIndices() {
	std::vector<int> completedRows{};
	for (int y = 0; y <= MAX_Y; y++) {
		if (isRowCompleted(y)) {
			completedRows.push_back( y );
		}
	}
	return completedRows;
}

void Gameboard::removeRow(int rowIndex) {
	assert(isRowCompleted( rowIndex ) && "Incomplete Row");

	for (int row = rowIndex; row > 0; row--) {
		copyRowIntoRow(row - 1, row);
	}
	fillRow(0, EMPTY_BLOCK);
}

// Given a vector of row indices, remove them. 
//   Ensure the indices of the vector in ascending order (sort it). Usually they 
//   are but to make this method "bulletproof" we shouldn't make assumptions.  
//   Best to make a copy and sort the copy (since param1 will likely be const). 
//   Iterate through the vector, call removeRow() on each row index. 
// - param 1: a vector of integers representing row indices we want to remove
// - return: nothing
//void removeRows(std::vector<int> rowIndexes);