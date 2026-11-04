#include "Tetromino.h"

void Tetromino::setShape(TetShape shape) { 
	this->shape = shape; 
	
	switch (shape) {
		case TetShape::S:
			blockLocs = { Point(0,0), Point(-1,0), Point(0,1), Point(1,1) };
			color = { TetColor::RED };
			break;
		case TetShape::Z:
			blockLocs = { Point(0,0), Point(1,0), Point(0,1), Point(-1,1) };
			color = TetColor::GREEN;
			break;
		case TetShape::L:
			blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(1,-1) };
			color = TetColor::ORANGE;
			break;
		case TetShape::J:
			blockLocs = { Point(0,0), Point(0,1), Point(0,-1), Point(-1,-1) };
			color = TetColor::BLUE_DARK;
			break;
		case TetShape::O:
			blockLocs = { Point(0,0), Point(0,1), Point(1,0), Point(1,1) };
			color = TetColor::YELLOW;
			break;
		case TetShape::I:
			blockLocs = { Point(0,0), Point(0,1), Point(0,2), Point(0,-1) };
			color = TetColor::BLUE_LIGHT;
			break;
		case TetShape::T:
			blockLocs = { Point(0,0), Point(0,-1), Point(1,0), Point(-1,0) };
			color = TetColor::PURPLE;
			break;
		default:
			break;
	}
}

void Tetromino::printToConsole() const {
	for (int y{ 3 }; y >= -3; y--) { //x coord
		for (int x{ -3 }; x <= 3; x++) { // y coord
			bool isPoint{ false };
			for (int ptIdx{ 0 }; ptIdx < blockLocs.size(); ptIdx++) { // blocklocks index
				if (Tetromino::blockLocs[ptIdx].getX() == x && Tetromino::blockLocs[ptIdx].getY() == y) {
					isPoint = true;
					break;
				}
			}
			if (isPoint == false) { std::cout << '.'; }
			else { std::cout << 'x'; }
		}
		std::cout << '\n';
	}
}

void Tetromino::rotateClockwise() {
	if (getShape() == TetShape::O) {
		return;
	}

	for (int i{ 0 }; i < blockLocs.size(); i++) {
		Point& block = blockLocs[i];
		block.multiplyX(-1);
		block.swapXY();
	}
}