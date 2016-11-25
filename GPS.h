#pragma once
#include "Vector.h"

class GPS {
public:
	Vector *head;
	Vector *tail;

	GPS();

	void getLocation(int);
	void print(int);
	Vector* getNode(int);


};