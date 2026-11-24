#include "Shape.h"
#include <stdexcept>
#include <string>

//Constructor, color por defecto
Shape::Shape() : color("red") {}

//Constructor , color elegido
Shape::Shape(std::string color) {
	set_color(color);
}

//Devuelve el color de relleno de la figura
std::string Shape::get_color() const {
	return color;
}

//Modifica el color de relleno 
void Shape::set_color(std::string c) {
	if (c == "red" || c == "green" || c == "green") {
		color = c;
	} else {
		throw std::invalid_argument("Color no válido. Debe ser 'red' , 'green'o 'blue'.");
	}	
}
