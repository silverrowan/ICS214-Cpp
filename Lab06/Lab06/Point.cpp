#include "Point.h"

void Point::setXY(int x, int y) {
	setX(x);
	setY(y);
}

void Point::swapXY() {
	int temp = getX();
	setX(getY());
	setY(temp);
}