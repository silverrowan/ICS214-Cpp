#include "GameboardItem.h"
#include "Gameboard.h"

GameboardItem::GameboardItem(const std::string& name, const std::string symbol) : name{ name }, symbol{ symbol } {
}

GameboardItem::~GameboardItem() {
	// return the sprite to the heap
	if (pSprite) {
		delete pSprite;
		pSprite = nullptr;
	}
}

void GameboardItem::loadImage(const std::string& filePath) {
	std::cout << "loading image: " << filePath << "\n";		

	bool success = texture.loadFromFile(filePath);
	if (!success) {
		std::string errorMsg = "missing file: ";
		errorMsg += filePath;
		throw std::runtime_error(errorMsg);
	}
	else {
		std::cout << filePath << " loaded succesfully\n";
	}
	
	pSprite = new sf::Sprite(texture);
}

void GameboardItem::draw(sf::RenderWindow& window) {
	// if the item doesn't have an associated board, don't draw it.
	if (!pBoard) { return; }

	// determine pixel offset to draw the item at (based on board offset & board position)
	// 
	// TODO: uncomment the rest of this line once Points can be added together!
	Point pos = pBoard->getTopLeftOffset() +Point(position.getX() * pBoard->getSquareWidth(), position.getY() * pBoard->getSquareHeight());

	// place the sprite there and then draw it
	pSprite->setPosition( sf::Vector2f( pos ));  // this would be nicer if we could use an implict conversion to convert Point to sf::Vector2f
	window.draw(*pSprite);	
}
