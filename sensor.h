#pragma once
#include "Vector.h"

class sensor {
public:
	Vector *head;
	Vector *tail;
	bool eof;
	double sum;

	sensor();

	void getAcceleration(int);
	double getAverageZ();
	void printZ(int);
	Vector* getNode(int);

};
