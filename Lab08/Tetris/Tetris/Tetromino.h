#pragma once
#include <vector>
#include "Point.h"

enum class TetColor { RED, ORANGE, YELLOW, GREEN, BLUE_LIGHT, BLUE_DARK, PURPLE, COUNT };
enum class TetShape{ S, Z, L, J, O, I, T, COUNT };

class Tetromino
{
	//FRIENDS
	friend class TestSuite;

private:
	TetColor color{}; // enum for color of the tetromino
	TetShape shape{}; // enum for shape of the tetromino (block arrangement)
	
	// array of block locations (with reference to self) of each block in tetromino 
	std::vector<Point> blockLocs{}; 

public:
	/// <summary>
	/// constructor, initializes tetromino shape (to block)
	/// </summary>
	Tetromino() {
		setShape(TetShape::O);
	};

	// return the color enum of the tetromino
	// param: none
	// return: color enum (TetColor)
	TetColor getColor() const { return color; }

	// return the shape enum of the tetromino
	// param: none
	// return: shape enum (TetShape)
	TetShape getShape() const { return shape; }

	// return a vector of the locations of each block in the tetshape
	// param: none
	// return: vector of points, grid locations of each block
	std::vector<Point> getBlockLocs() const { return blockLocs; }

	// - set the shape
	// - set the blockLocs for the shape 
	// - set the color for the shape
	void setShape(TetShape shape);

	// print a grid to display the current shape 
	// to do this: print out a “grid” of text to represent a co-ordinate 
	// system.  Start at top left [-3,3] go to bottom right [3,-3] 
	// (use nested for loops) 
	//  for each [x,y] point, loop through the blockLocs and if the point exists 
	// in the list, print an 'x' instead of a '.'. You should end up with something 
	// like this: (results will vary depending on shape and rotation, eg: this 
	//  one shows a T shape rotated clockwise once) 
	//  ....... 
	//  ....... 
	//  ...x... 
	//  ..xx... 
	//  ...x... 
	//  ....... 
	void printToConsole() const;

	// rotate the shape 90 degrees around [0,0] (clockwise) 
	// to do this: 
	//  
	//  - iterate through blockLocs - rotate each Point 90 degrees clockwise around [0,0] 
	// hint: as you rotate the point [1,2] clockwise around [0,0], note 
	// how the x,y values change. Once you find the pattern you can use 
	// a couple existing methods in the Point class to accomplish this.   
	// make it so that the TetShape::O doesn’t rotate 
	void rotateClockwise();

	// pick a random shape and return it
	// params: none
	// return: TetShape enum, the tetromino shape
	static TetShape getRandomShape();
};

