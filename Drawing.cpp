#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"

// Constructor por defecto, reserva memoria dinámica para shapes usando ListArray<Shape*>
Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

// Destructor: libera la memoria dinámica reservada para shapes
Drawing::~Drawing() {
    delete shapes;
}

// Añade la figura shape al frente del dibujo (al inicio de la lista)
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añade la figura shape al fondo del dibujo (al final de la lista)
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Muestra por pantalla todas las figuras del dibujo reutilizando print()
void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
    }
}

// Devuelve la suma del área de todos los círculos presentes en el dibujo
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr) {
            total_area += c->area();
        }
    }
    return total_area;
}

// Mueve todos los cuadrados del dibujo sumando incX e incY
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr) {
            s->translate(incX, incY);
        }
    }
}
