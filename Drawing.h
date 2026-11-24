#ifndef DRAWING_H
#define DRAWING_H

#include "List.h"
#include "Shape.h"

class Drawing {
    private:
        // Puntero a una lista polimórfica de figuras (el primero va al frente y el último al fondo)
        List<Shape*>* shapes;

    public:
        // Constructor por defecto
        Drawing();

        // Destructor, libera la memoria dinámica reservada por shapes
        ~Drawing();

        // Añade la figura shape al frente del dibujo (al inicio de la lista)
        void add_front(Shape* shape);

        // Añade la figura shape al fondo del dibujo (al final de la lista)
        void add_back(Shape* shape);

        // Muestra por pantalla la información de todas las figuras del dibujo
        void print_all();

        // Devuelve la suma de las áreas de todos los círculos del dibujo
        double get_area_all_circles();

        // Mueve todos los cuadrados del dibujo sumando incX e incY
        void move_squares(double incX, double incY);
};

#endif
