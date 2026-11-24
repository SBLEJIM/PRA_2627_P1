#include <iostream>
#include <stdexcept>
#include <string>
#include "Rectangle.h"

// Comprueba si v0-v1 y v2-v3 miden lo mismo, y si v1-v2 y v3-v0 miden lo mismo
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d23) && (d12 == d30);
}

//Constructor por defecto: color por defecto y los 4 vértices pedidos
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

//Constructor con color y 4 vértices
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vértices no válidos para un rectángulo.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

//Constructor de copia: crea un array nuevo y copia el color y los 4 vértices
Rectangle::Rectangle(const Rectangle &r) : Shape(r.get_color()) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

//Destructor, libera la memoria del array vs
Rectangle::~Rectangle() {
    delete[] vs;
}

//Devuelve el vértice ind
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}

//Operador [], devuelve el vértice ind usando get_vertex
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

//Cambia los 4 vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Vértices no válidos para un rectángulo.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

//Operador =: copia color y vértices en un rectángulo ya existente
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        set_color(r.get_color());
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

//Metodos heredados

//Calcula el área: d(v0, v1) * d(v1, v2)
double Rectangle::area() const {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

//Calcula el perímetro: 2 * (d(v0, v1) + d(v1, v2))
double Rectangle::perimeter() const {
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

//Suma incX e incY a cada vértice
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

//Imprime el rectángulo usando operator<<
void Rectangle::print() {
    std::cout << *this;
}

//(Suya)Muestra el color y los 4 vértices del rectángulo
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.get_color()
        << "; v0 = " << r.vs[0]
        << "; v1 = " << r.vs[1]
        << "; v2 = " << r.vs[2]
        << "; v3 = " << r.vs[3] << "]";
    return out;
}
