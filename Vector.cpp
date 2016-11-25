
#include "Vector.h"

Vector::Vector(double a, double b) {
	//constructor for the coordinates
	x = a;
	y = b;
	next = NULL;
}

Vector::Vector(double _x, double _y, double _z) {
	//constructor for the sensor values
	x = _x;
	y = _y;
	z = _z;
	next = NULL;
	coordinates = NULL;
}