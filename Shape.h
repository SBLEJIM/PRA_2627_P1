#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape {
    protected:
	    //Color de la figura: red, green, azul
	    std::string color;
    
    public:
	    //Constructor por defecto, figura de color rojo
	    Shape();

	    //Construcor, figura del color específico
	    Shape(std::string color);

	    //Destructor activa el polimorfismo : virtual
	    virtual ~Shape() = default;

	    //Devuelve el color de relleno de la figura
	    std::string get_color() const;

	    //Modifica el color de relleno: solo red, green y blue
	    void set_color(std::string c);

	    //Metodo virtual puro, calcula el area de la figura
	    virtual double area() const = 0;

	    //Metodo virtual puro, calcula el perimetro de la figura
	    virtual double perimeter() const = 0;

	    //Metodo virtual puro, traslada la figura sobre el espacio, aplicando los incrementos de X e Y proporcionados
	    virtual void translate(double incX, double incY) = 0;

	    //Metodo virtual puro, imprime por pantalla la informacion de la figura
	    virtual void print() = 0;
};

#endif
