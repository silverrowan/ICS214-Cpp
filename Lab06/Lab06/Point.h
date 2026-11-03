#pragma once
#include <iostream>
#include <sstream>
#include <string>
class Point
{
private:
	int x{ -1 };
	int y{ -1 };

public:
	Point() {};

	Point(int xIn, int yIn) : x{ xIn }, y{ yIn } {}

	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; } // do these need to be refs? getters never should be, but setters?
	void setY(int y) { this->y = y; }

	/// <summary>
	/// Set values of x & y to specified. Alters original.
	/// </summary>
	/// <param name="x">int, 'column'</param>
	/// <param name="y">int, 'row'</param>
	void setXY(int x, int y);

	/// <summary>
	/// Swap values of x & y coordinates. Alters originals.
	/// </summary>
	void swapXY();

	/// <summary>
	/// Multiply x coord by factor specified. Alters original.
	/// </summary>
	/// <param name="factor">int, multiplier</param>
	void multiplyX(int factor) { x *= factor; }

	/// <summary>
	/// Multiply y coord by factor specified. Alters original.
	/// </summary>
	/// <param name="factor">int, multiplier</param>
	void multiplyY(int factor) { y *= factor; }

	/// <summary>
	// return a string in the form "[x,y]" to represent the state of the Point instance  
	// (for debugging) You could use stringstream if you want to try a forming a string in  
	// the same way you use cout https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/ 
	/// </summary>
	/// <returns>string of coordinates</returns>
	std::string toString();

	/// <summary>
	/// Print out coordinates to terminal in format [x,y]
	/// </summary>
	void printCoords() { std::cout << "[" << (getX()) << "," << (getY()) << "]"; }
};

