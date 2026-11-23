#pragma once
#include "Gameboard.h"
#include "Gameboarditem.h"

// This class implements a unique GameboardItem that is not found in regular Chess.
// A "Blocker" is a GameboardItem that is like a rock that sits on a square on the gameboard.
// - It cannot be moved.
// - It prevents ChessPieces from moving to the square is occupies.
 
class Blocker : public GameboardItem {
public:
	// constructor
	Blocker();

	// get the image filename
	std::string getImageFilepath() override;		
};