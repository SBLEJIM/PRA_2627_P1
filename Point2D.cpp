#include <ostream>
#include <cmath>
#include "Point2D.h"

//Constructor 
Point2D::Point2D(double x, double y) : x(x), y(y) {}

//Método estático para calcular la ditancia euclidiana entre a y b
double Point2D::distance(const Point2D &a, const Point2D &b) {
	return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

//Sobrecarga ==, el const evita que se modifique el objeto actual
bool Point2D::operator==(const Point2D &other) const{
	return (x == other.x) && (y == other.y);
}

//Sobrecarga !=
bool Point2D::operator!=(const Point2D &other) const {
	return !(*this == other);
}

//Sobrecarga << 
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}
