#pragma once
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Vector {
public:
	double x, y, z;
	Vector* next;
	Vector *coordinates;

	Vector(double, double);//GPS
	Vector(double, double, double);//Sensor

};