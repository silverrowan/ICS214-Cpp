#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sstream>

// A class for encapsulating a 2D Point.  ie: XY coordinates
class Point {
private:
	int x{ 0 };		// x coordinate
	int y{ 0 };		// y coordinate

public:
	// constructor
	Point(int x = 0, int y = 0) : x{ x }, y{ y } {}

	// setters
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	void setXY(int x, int y) { this->x = x; this->y = y; }

	// getters
	int getX() const { return x; }
	int getY() const { return y; }

	// other
	void swapXY() { int temp = x; x = y; y = temp; }

	// multiplication
	void multiplyX(int factor) { x *= factor; }
	void multiplyY(int factor) { y *= factor; }	

	std::string toString() const;

// --------- only need *** one of *** method or function form for opp overloading; shown for demo purposes -----------------
// --------- *** some may only work one way or the other; ***

	// operator overload for adding 2 points together - written as a method
	Point operator+(const Point& other) {
		return Point(x + other.x, y + other.y);
	}
	// operator overload for testing if 2 points are equal - written as a method
	bool operator==(const Point& other) {
		return x == other.x && y == other.y;
	}


	operator sf::Vector2i() const;
	operator sf::Vector2f() const;
};

// operator overload for adding 2 points together - written as a function
Point operator+(const Point& pt1, const Point& pt2);

// operator overload for testing if 2 points are equal - written as a function
bool operator==(const Point& pt1, const Point& pt2);

// operator overload for the insertion operator (used for printing a Point to the console)
// - must be written as a function (a method will not work)
std::ostream& operator<<(std::ostream& out, const Point& pt);
