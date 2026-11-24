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
	ChessPiece( const std::string& name, Color col );
	virtual ~ChessPiece() {}

	// get the color (of the chess piece)
	Color getColor() { return color; }

	// get the image filepath (of the chess piece)
	std::string getImageFilepath() override;

	// STATIC ---------- //	
	// get the opposite color of the color passed in
	static Color getOppositeColor(Color col);

	/// <summary>
	/// Virtual function call for moving the chess pieces. To be overwritten
	/// by each derived chess piece.
	/// </summary>
	/// <returns>valid movement end locations</returns>
	virtual const std::vector<Point> getValidMoves() const = 0;

	/// <summary>
	/// Checks if the location is a placement for the calling piece
	/// </summary>
	/// <param name="destination">Point, (x,y) coordinates of target square</param>
	/// <returns>bool, True if placement is valid</returns>
	bool isValidMove(const Point& destination);

	/// <summary>
	/// Checks if the location is a valid move for the calling piece
	/// confirms placement and destination contents are all legal 
	/// (* note, no checking for check on king)
	/// </summary>
	/// <param name="destination">Point, (x,y) coordinates of target square</param>
	/// <returns>bool, True if move is valid</returns>
	bool isValidColorTarget(const Point& destination) const;

	/// <summary>
	/// Get a vector of valid move targets for a piece
	/// </summary>
	/// <param name="offsets">std::vector<Point>& full set of possible moves for a 
	/// particular piece regardless of board etc</param>
	/// <returns>std::vector<Point> the set of possible moves after considering board conditions</returns>
	std::vector<Point> getValidColorTargets(const std::vector<Point>& offsets) const;
};
