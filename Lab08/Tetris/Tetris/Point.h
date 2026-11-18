#pragma once
#include <iostream>
#include <sstream>
#include <string>
class Point
{
private:
	int x{ -1 }; // x-coordinate; starts at 0, ends at MAX_X-1 (left to right)
	int y{ -1 }; // y-coordinate; starts at 0, ends at MAX_Y-1 (top-down)

public:

	/// <summary>
	/// constructor; initialize member vars 
	/// </summary>
	/// <param name="xIn">int, x-coordinate</param>
	/// <param name="yIn">int, y-coordinate</param>
	Point(int xIn = 0, int yIn = 0) : x{ xIn }, y{ yIn } {}

	// do we need to do comments for setters/getters?

	/// <summary>
	/// returns value of x-coordinate
	/// </summary>
	/// <returns>int x; x-coordinate </returns>
	int getX() const { return x; } 
	
	/// <summary>
	/// returns value of y-coordinate
	/// </summary>
	/// <returns>in y; y-coordinate</returns>
	int getY() const { return y; } 

	/// <summary>
	/// sets (new) value for x-coordinate
	/// </summary>
	/// <param name="x">int; x coordinate (index)</param>
	void setX(int x) { this->x = x; } 

	/// <summary>
	/// sets (new) value for y-coordinate
	/// </summary>
	/// <param name="y">int, y coordinate (index)</param>
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
	void multiplyX(int factor) { setX( getX()*factor ) ; }

	/// <summary>
	/// Multiply y coord by factor specified. Alters original.
	/// </summary>
	/// <param name="factor">int, multiplier</param>
	void multiplyY(int factor) { setY( getY()*factor ) ; }

	/// <summary>
	// return a string in the form "[x,y]" to represent the state of the Point instance  
	// (for debugging) You could use stringstream if you want to try a forming a string in  
	// the same way you use cout https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/ 
	/// </summary>
	/// <returns>string of coordinates</returns>
	std::string toString () const;

	/// <summary>
	/// Print out coordinates to terminal in format [x,y]
	/// </summary>
	void printCoords() const { std::cout << "[" << (getX()) << "," << (getY()) << "]" ; }
};
