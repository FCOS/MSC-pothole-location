
#pragma once
#include "GPS.h"
#include "sensor.h"
#include "Vector.h"

using namespace std;

class combinedList {
public:
	Vector *head;
	Vector *tail;

	combinedList();
	void addDescending(Vector*);
	void print();
};

