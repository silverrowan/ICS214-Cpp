#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "Point.h"

namespace Constants {
	const std::string pathToImages = "../assets/images/";

	const Point gameboardOffset = { 35, 35 };	// offset of gameboard top left in pixels
	const int gameboardSquareWidth = 84;		// square pixel width 
	const int gameboardSquareHeight = 84;		// square pixel height

	const sf::Color colorLight = sf::Color(220, 220, 220, 255);     // color for "white" squares
	const sf::Color colorDark = sf::Color(100, 100, 100, 255);      // color for "black" squares
	const sf::Color colorSelected = sf::Color(255, 0, 0, 80);		// color for selected square 
	const sf::Color colorPotentialMove = sf::Color(0, 255, 0, 80);	// color for potential moves
}