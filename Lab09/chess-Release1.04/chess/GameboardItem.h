#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>
#include "Point.h"
#include "ISerializable.h"

  
// If Gameboard.h #includes GameboardItem.h, and GameboardItem.h #includes Gameboard.h this causes
// a circular reference - resulting in errors that are often tricky to diagnose!
// 
// To prevent this: We move the #include Gameboard.h statement (that you would normally expect here) to the
// GameboardItem.cpp file.
// 
// However, the GameboardItem class still needs to know that something called a Gameboard exists 
// (a GameboardItem contains a reference to a Gameboard!), so we replace it with the "class Gameboard" 
// declaration - which is essentially a promise that the definition will come later (in the .cpp file where 
// the #include Gameboard.h statement happens)
//#include "Gameboard.h"
class Gameboard;


class GameboardItem {
protected: 
	std::string name;					// name of the item (used to form the image filename,
										// and to output debug info)
	Point position = {-1,-1};			// the item's position on the Gameboard
 
	const Gameboard* pBoard{ nullptr };	// a pointer to the gameboard the piece is on (nullptr if not
										// associated with a board yet).

	sf::Texture texture;				// a texture (to store the item's image)	
	sf::Sprite* pSprite{ nullptr };		// a sprite (to display the texture).  This is a pointer because
										// to construct it we first need to give it a loaded texture.
	const std::string symbol;			// text symbol for the item

public:
	// constructor
	GameboardItem(const std::string& name, const std::string symbol="?");

	// destructor
	virtual ~GameboardItem();

	// tell the item that it is now on a gameboard
	void setGameboard(Gameboard* pGB) {	pBoard = pGB; }

	// get the name of the Gameboard item (ie: king, knight, etc.)
	std::string getName() { return name; }

	// get the path & filename of the image
	virtual std::string getImageFilepath() = 0;

	// get the position of the item (in board coordinates)
	Point getPosition() const {	return position; }

	// set the position of the item (in board coordinates)
	void setPosition(const Point& p) { position = p; }

	// get the symbol for the item (char) ( alternate name for toString() )
	const std::string& getSymbol() const { return symbol; }

	//ISerializable function toString()
	const std::string& toString() const { return symbol; }

	// load the image that represents this item
	void loadImage(const std::string& filePath);

	// draw the image of the item on the screen
	void draw(sf::RenderWindow& window);
};
