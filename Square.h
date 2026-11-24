#ifndef SQUARE_H
#define SQUARE_H

#include <ostream>
#include <string>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
    private:
        //Comprueba si las 4 aristas de vertices tienen la misma longitud
        static bool check(Point2D* vertices);

    public:
        //Constructor por defecto: color por defecto y vértices (-1,1), (1,1), (1,-1), (-1,-1)
        Square();

        //Constructor con color y 4 vértices
        Square(std::string color, Point2D* vertices);

	//Metodos heredadas

        //Cambia los 4 vértices
        void set_vertices(Point2D* vertices) override;

        //Imprime el cuadrado por pantalla
        void print() override;

        //Sobrecarga de << 
        friend std::ostream& operator<<(std::ostream &out, const Square &square);
};

#endif
