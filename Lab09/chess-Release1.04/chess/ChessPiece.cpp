#include "ChessPiece.h"
#include "Constants.h"
#include "Point.h"
#include "Gameboard.h"

ChessPiece::ChessPiece(const std::string& name, Color col) 
	: GameboardItem{ name }, color(col) {
	loadImage(getImageFilepath());
}


std::string ChessPiece::getImageFilepath() {
	std::stringstream ss;
	ss << Constants::pathToImages;
	// the color forms part of the filename we want to load (of the chess piece).
	if (color == Color::white) {
		ss << "w";
	}
	else {
		ss << "b";
	}
	ss << "_" << name << ".png";
	return ss.str();
}

bool ChessPiece::isValidMove(const Point& destination) const {
	std::vector<Point> validMoves = getValidMoves();
	for (int i = 0; i < validMoves.size(); i++) {
		if (validMoves[i] == destination) {
			return true;
		}
	}
	return false;
}
