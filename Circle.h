#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
	private: 
		Point2D center;
		double radius;
	public:
		//Constructor, crea un ciruclo de color por defecto de centro (0,0) y radio 1
		Circle();
		
		//Constructor 
		Circle(std::string color, Point2D center, double radius);

		//Metodo consultor de center
		Point2D get_center() const;

		//Metodo modificador de center
		void set_center(Point2D p);

		//Metodo consultor de radius
		double get_radius() const;

		//Metodo modificador de radius
		void set_radius(double r);

		//Metodos heredados

		double area() const override;
		double perimeter() const override;

		//Mueve el circulo sumando incX e incY
		void translate(double incX, double incY) override;

		//Muestra los datos del circulo 
		void print() override;

		
		//Permite std::cout << circulo
		friend std::ostream& operator<<(std::ostream &out, const Circle &c);	
};

#endif
