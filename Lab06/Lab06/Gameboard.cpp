//#include <iomanip>
//#include "Gameboard.h"
//#include "Point.h"
//#include "Tetromino.h"
//
//	//static const int MAX_X = 10;		// gameboard x dimension
//	//static const int MAX_Y = 19;		// gameboard y dimension
//	//static const int EMPTY_BLOCK = -1;	// contents of an empty block
//
//
//	// the gameboard - a grid of X and Y offsets.  
//	//  ([0][0] is top left, [MAX_Y-1][MAX_X-1] is bottom right) 
//	//int grid[MAX_Y][MAX_X];
//
//Gameboard::Gameboard() : grid{ } {
//	empty();
//}
//
//void Gameboard::empty() {
//	for (int y = 0; y < Gameboard::MAX_Y; y++) { //row/y
//		fillRow(y, Gameboard::EMPTY_BLOCK);
//	}
//}
//
//// print the grid contents to the console (for debugging purposes)
////   use std::setw(2) to space the contents out 
////   (google it, you'll need to #include <iomanip>).
////   If the content == EMPTY_BLOCK, print a '.', otherwise print the content.
//// - params: none
//// - return: nothing
////void printToConsole();
//
//void Gameboard::setContent(std::vector<Point> pts, int content) {
//	for (int i = 0; i < pts.size(); i++) {
//		Point targetPt = pts.at(i);
//		Gameboard::setContent( targetPt, content);
//	}
//}
//
//bool Gameboard::isValidPoint(Point pt) {
//	int x = pt.getX();
//	int y = pt.getY();
//
//	return Gameboard::isValidPoint(x, y);
//}
//
//bool Gameboard::isValidPoint(int x, int y) {
//	if (x > Gameboard::MAX_X || y > Gameboard::MAX_Y || x < 0 || y < 0) {
//		return false;
//	}
//	else { return true; }
//}
//
//bool isRowCompleted(int rowIndex) {
//	for (int x = 0; x < Gameboard::MAX_X; x++) {
//		if (getContent(x, rowIndex) == Gameboard::EMPTY_BLOCK) {
//			return false;
//		}
//	}
//	return true;
//}
//
//void Gameboard::fillRow(int rowIndex, int content) {
//	for (int x = 0; x < Gameboard::MAX_X; x++) { //col/x
//		setContent(x, rowIndex, Gameboard::EMPTY_BLOCK);
//	}
//}
//
//
//getContent(x, y)