#pragma once

#include <SFML/Graphics.hpp>
#include "GameboardItem.h"
#include <vector>
#include <sstream>

class Gameboard;


// This class is used as a base class for moveable chess pieces.  
// Specific chess pieces (King, Knight, etc.) are intended to inherit from this class,
// and implement functionality unique to each chess piece.

class ChessPiece : public GameboardItem {
public:
	enum class Color { black, white };	// black == blue, white == red (for the gfx in this game)

protected:
	const Color color;	// color of the chess piece

public:
	// constructor
	ChessPiece(const std::string& name, Color col );

	// get the color (of the chess piece)
	Color getColor() { return color; }

	// get the image filepath (of the chess piece)
	std::string getImageFilepath() override;


	// STATIC ---------- //	
	// get the opposite color of the color passed in
	static Color getOppositeColor(Color col) {
		return col == Color::white ? Color::black : Color::white;
	}

	virtual std::vector<Point>& getValidMoves() = 0;

	bool isValidMove(const Point& destination);

	bool isValidColorTarget(const Point& destination) const;

	std::vector<Point>& getValidColorTargets(const std::vector<Point>& offsets) const;
};
