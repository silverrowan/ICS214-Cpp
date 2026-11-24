#include "ConcreteChessPieces.h"
#include "Gameboard.h"
#include "Blocker.h"
#include "Point.h"
#include <sstream>

// Initialize name (owned by the derived class: ChessPiece) to "king"
King::King(const Color col) : ChessPiece( "king", col, "K") {
}

const std::vector<Point> King::getValidMoves() const {
	std::vector<Point> validOffsets{ {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
	std::vector<Point> targets = getValidColorTargets(validOffsets);
	return targets;
}

// Initialize name (owned by the derived class: ChessPiece) to "knight"
Knight::Knight(Color col ) : ChessPiece("knight", col, "k") {
}

const std::vector<Point> Knight::getValidMoves() const {
	return getValidColorTargets({ {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2} }); // same as for king, but more concise
}


