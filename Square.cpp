#include <iostream>
#include <stdexcept>
#include <string>
#include "Square.h"

//Comprueba si las 4 aristas del cuadrado tienen la misma longitud
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d12) && (d12 == d23) && (d23 == d30);
}

//Constructor por defecto, color por defecto y vértices (-1,1), (1,1), (1,-1), (-1,-1)
Square::Square() : Rectangle() {
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

//Constructor con color y 4 vértices
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

//Metodos heredados

//Cambia los 4 vértices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

//Imprime operator<<
void Square::print() {
    std::cout << *this << std::endl;
}

// Muestra el color y los 4 vértices 
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.get_color()
        << "; v0 = " << square.vs[0]
        << "; v1 = " << square.vs[1]
        << "; v2 = " << square.vs[2]
        << "; v3 = " << square.vs[3] << "]";
    return out;
}
