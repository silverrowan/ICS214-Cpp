#include "Tetromino.h"

void Tetromino::setShape(TetShape shape) { 
	this->shape = shape; 
	
	switch (shape) {
	case TetShape::S:
		blockLocs = { Point(0,0), Point(-1,0), Point(0,1), Point(1,1) };
		color = TetColor::RED;
	case TetShape::Z:
		blockLocs = { Point(0,0), Point(1,0), Point(0,1), Point(-1,1) };
		color = TetColor::GREEN;
	case TetShape::L:
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(1,-1) };
		color = TetColor::ORANGE;
	case TetShape::J:
		blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(-1,-1) };
		color = TetColor::BLUE_DARK;
	case TetShape::O:
		blockLocs = { Point(0,0), Point(0,1), Point(1,0), Point(1,1) };
		color = TetColor::YELLOW;
	case TetShape::I:
		blockLocs = { Point(0,0), Point(0,1), Point(0,2), Point(0,-1) };
		color = TetColor::BLUE_LIGHT;
	case TetShape::T:
		blockLocs = { Point(0,0), Point(0,-1), Point(1,0), Point(-1,0) };
		color = TetColor::PURPLE;
	}
}

// print a grid to display the current shape 
// to do this: print out a “grid” of text to represent a co-ordinate 
// system.  Start at top left [-3,3] go to bottom right [3,-3] 
// (use nested for loops) 
//  for each [x,y] point, loop through the blockLocs and if the point exists 
// in the list, print an 'x' instead of a '.'. You should end up with something 
// like this: (results will vary depending on shape and rotation, eg: this 
//  one shows a T shape rotated clockwise once) 
//  ....... 
//  ....... 
//  ...x... 
//  ..xx... 
//  ...x... 
//  ....... 
void Tetromino::printToConsole() {
	for (int i = -3; i <= 3; i++) { //x coord
		for (int k = 3; k >= -3; k--) { // y coord
			bool isPoint = false;
			for (int p = 0; p < blockLocs.size(); p++) { // blocklocks index
				if (Tetromino::blockLocs[p].getX() == i && Tetromino::blockLocs[p].getY() == k) {
					isPoint = true;
					break;
				}
			}
		}
	}

	std::cout << 
}