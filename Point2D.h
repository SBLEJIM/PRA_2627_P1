#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D{
	public: 
		double x;
		double y;

		//Constructor
		Point2D(double x=0.0, double y=0.0);

		//Calcula la distancia eucladiana entre a y b
		static double distance(const Point2D &a, const Point2D &b);

		//Sobrecarga ==, comprueba si dos puntos son iguales
		bool operator==(const Point2D &other) const;

		//Sobrecarga !=, comprueba si dos puntos son diferentes
		bool operator!=(const Point2D &other) const;

		//Sobrecarga <<
		friend std::ostream& operator <<(std::ostream &out, const Point2D &p);
};

#endif
