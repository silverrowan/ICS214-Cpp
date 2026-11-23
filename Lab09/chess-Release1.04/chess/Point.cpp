#include "Point.h"


std::string Point::toString() const {
	std::stringstream ss;
	ss << "[" << x << "," << y << "]";
	return ss.str();
}

Point operator+(const Point& pt1, const Point& pt2) {
	return Point(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
}

bool operator==(const Point& pt1, const Point& pt2) {
	return pt1.getX() == pt2.getX() && pt1.getY() == pt2.getY();
}

std::ostream& operator<<(std::ostream& out, const Point& pt) {
	out << "[" << pt.getX() << "," << pt.getY() << "]";
	return out;
}