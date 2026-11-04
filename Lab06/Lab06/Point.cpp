#include "Point.h"

void Point::setXY(int x, int y) {
	setX(x);
	setY(y);
}

void Point::swapXY() {
	int temp{ getX() };
	setX( getY() );
	setY( temp );
}

std::string Point::toString() const {
	std::stringstream string{};
	string << "[" << getX() << "," << getY() << "]";
	return string.str();
}