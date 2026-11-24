#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Circle.h"

static const double PI = 3.141592;

//Constructor por defecto: crea un círculo rojo, centro (0,0) y radio 1
Circle::Circle() : Shape(), center(0.0, 0.0), radius(1.0) {}

//Constructor con parámetros: pasa el color a Shape
Circle::Circle(std::string color, Point2D center, double radius)
    : Shape(color), center(center), radius(0.0) {
    set_radius(radius);
}

//Devuelve el centro actual del círculo
Point2D Circle::get_center() const {
    return center;
}

//Cambia el centro del círculo por el punto recibido
void Circle::set_center(Point2D p) {
    center = p;
}

//Devuelve el radio actual del círculo
double Circle::get_radius() const {
    return radius;
}

//Cambia el radio y lanza error si es negativo
void Circle::set_radius(double r) {
    if (r < 0.0) {
        throw std::invalid_argument("El radio no puede ser negativo.");
    }
    radius = r;
}

//Metodos heredados

// Calcula el área, PI * r^2
double Circle::area() const {
    return PI * std::pow(radius, 2);
}

// Calcula el perímetro, 2 * PI * r
double Circle::perimeter() const {
    return 2.0 * PI * radius;
}

//Mueve el centro sumando incX e incY
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Imprime el círculo
void Circle::print() {
    std::cout << *this << std::endl;
}

// Define cómo se imprime un Circle, <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.get_color()
        << "; center = " << c.center
        << "; radius = " << c.radius << "]";
    return out;
}
