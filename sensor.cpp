#include "sensor.h"

sensor::sensor() {
	//default constructor
	head = NULL;
	tail = NULL;
	eof = false;
}

void sensor::getAcceleration(int pos) {
	double  x, y, z;
	int i = 1;

	//opens file
	ifstream in;
	in.open("sensor.txt");
	if (in.fail()) {
		cout << "unable to open sensor.txt" << endl;
		return;
	}

	while (i <= pos) {
		if (in.eof()) {
			eof = true;
			return;
		}
		in >> x >> y >> z;
		i++;

	}

	//Creating the new vector with the acceleration values in it.
	Vector *newVector = new Vector(x, y, z);


	//If list is empty, make the new vector the head
	if (head == NULL) {
		head = tail = newVector;
	}

	//otherwise, itterate through the list, until you find the end, and attach it there.
	else {
		Vector* curr = head;
		Vector* prev = NULL;

		while (curr != NULL) {
			//Itterating through the linked list
			prev = curr;
			curr = curr->next;

		}

		curr = newVector;
		prev->next = curr;

	}
	//closing the file
	in.close();
}

double sensor::getAverageZ() {
	//Finds the average z
	Vector* curr = head;
	double sum = 0;
	double size = 0;

	//Itterates through the list
	while (curr != NULL) {
		//adds the current z to sum
		sum = sum + curr->z;
		size++;
		curr = curr->next;
	}

	//returns the average
	return sum / size;
}

void sensor::printZ(int a) {
	Vector* curr = head;
	//Prints the z coordinate at position 'a'

	for (int i = 1; i < a; i++) {
		//Itterates until position 'a'
		if (curr->next != NULL) {
			curr = curr->next;
		}
	}
	//if the value is positive, print a space, to align
	//positive and negative values
	if (curr->z >= 0) {
		cout << " ";
	}
	//print z values
	cout  << curr->z;
}


Vector* sensor::getNode(int pos) {
	//Returns a pointer to the node in position 'pos'
	Vector *curr = head;
	//Itterates through the list, until the 'pos'th 
	for (int i = 1; i < pos; i++) {
		curr = curr->next;
	}
	return curr;
}
