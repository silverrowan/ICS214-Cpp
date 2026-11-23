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

//class King : public ChessPiece {
//public:
//	King(Color col);
//};

//class Knight : public ChessPiece {
//public:
//	Knight(Color col);
//};

