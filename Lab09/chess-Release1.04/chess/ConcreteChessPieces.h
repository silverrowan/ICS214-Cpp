#pragma once

#include <vector>
#include "ChessPiece.h"
#include "Point.h"
class Gameboard;	// prevent circular references

// This file (and its associated .cpp), are intended to contain the "concrete" class
// definitions for individual chess pieces (king, knight, etc.).
// Each should be relatively short, and rather than having a file for each different
// piece, it seemed nicer to be able to simply #include "ConcreteChessPieces.h" when 
// you want to instantiate actual chess pieces.


// Use these class definitions as a starting point for creating your concrete classes.

class King : public ChessPiece {
public:
	King(Color col, std::string name = "king") : ChessPiece(name, col) {};

	std::vector<Point>& getValidMoves() override { 
		std::vector<Point> validOffsets{ {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
		std::vector<Point>& targets = getValidColorTargets(validOffsets);
		return targets;
	}
};

class Knight : public ChessPiece {
public:
	Knight(Color col, std::string name = "knight") : ChessPiece(name, col) {}

	std::vector<Point>& getValidMoves() override {
		return getValidColorTargets({ {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2} } ); // same as for king, but more concise
	}
};