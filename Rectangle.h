#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include "Shape.h"
#include "Point2D.h"


class Rectangle : public Shape {
    private:
        // Comprueba si 4 vértices forman un rectángulo válido
        static bool check(Point2D* vertices);

    protected:
        // Puntero al array dinámico de 4 vértices (v0, v1, v2, v3)
        Point2D* vs;

    public:
        // Número de vértices de un rectángulo (4)
        static int const N_VERTICES = 4;

        //Constructor por defect, color por defecto y vértices (-1,0.5), (1,0.5), (1,-0.5), (-1,-0.5)
        Rectangle();

        //Constructor con color y array de 4 vértices
        Rectangle(std::string color, Point2D* vertices);

        //Constructor de copia para copiar un rectángulo de forma segura
        Rectangle(const Rectangle &r);

        //Destructor para liberar la memoria dinámica del array vs
        ~Rectangle();

        //Devuelve el vértice en la posición ind
        Point2D get_vertex(int ind) const;

        //Operador [] para acceder al vértice en ind
        Point2D operator[](int ind) const;

        //Método virtual para cambiar los 4 vértices
        virtual void set_vertices(Point2D* vertices);

        //Operador de asignación = para copiar de forma segura un rectángulo
        Rectangle& operator=(const Rectangle &r);

        //Metodos heredados

       	//Calcula el área del rectángulo
        double area() const override;

        //Calcula el perímetro del rectángulo
        double perimeter() const override;

        //Traslada el rectángulo aplicando incX e incY a sus vértices
        void translate(double incX, double incY) override;

        //Imprime la información del rectángulo por pantalla
        void print() override;

        //Sobrecarga de << para mostrar el color y los 4 vértices del rectángulo
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
