#include "ChessPiece.h"
#include "Constants.h"
#include "Point.h"
#include "Gameboard.h"
#include <cassert>

ChessPiece::ChessPiece(std::string& name, Color col) 
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

bool ChessPiece::isValidMove(const Point& destination) {
	const std::vector<Point> validMoves = getValidMoves();
	for (int i = 0; i < validMoves.size(); i++) {
		if (validMoves[i] == destination) {
			return true;
		}
	}
	return false;
}

bool ChessPiece::isValidColorTarget(const Point& destination) const {
	assert(pBoard != nullptr && "piece must be on the board to move");

	if (!(*pBoard).isValid(destination)) { return false; }
	if ((*pBoard).containsBlockerAt(destination)) { return false; }
	if ((*pBoard).containsChessPieceOfColorAt(destination, color)) { return false; }
	return true;
}

std::vector<Point> ChessPiece::getValidColorTargets(const std::vector<Point>& offsets) const {
	std::vector<Point> validMoves{};
	if (pBoard) {
		Point origin = getPosition();

		for (int i = 0; i < offsets.size(); i++) {
			Point newPt = offsets[i] + origin;
			if (isValidColorTarget(newPt)) {
				validMoves.push_back(newPt);
			}
		}
	}
	return validMoves;
}