
#include "GPS.h"

GPS::GPS() {
	//default constructor for GPS
	head = NULL;
	tail = NULL;
}

void GPS::getLocation(int pos) {
	double  latitude, longitude;
	int i = 1;

	//opening the file
	ifstream in;
	in.open("GPS.txt");
	if (in.fail()) {
		cout << "unable to open GPS.txt" << endl;
		return;
	}


	//This is the very inefficient place. As I am trying to emulate going in and
	//out of the file every second, I need to itterate through the values until
	//I reach the new values, before adding them to the linked list. Again, to 
	//make this more efficient, I could just add all at once.
	while (i <= pos) {
		in >> latitude >> longitude;
		i++;

	}

	//Creating the new vector with the coordinates in it.
	Vector *newVector = new Vector(latitude, longitude);

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

void GPS::print(int a) {
	//Print method
	Vector* curr = head;

	//Itterating through the list to the desired 
	for (int i = 1; i < a; i++) {
		if (curr->next != NULL) {
			curr = curr->next;
		}
	}
	//printing the coordinates, with a prescicion of 4 decimal places.
	cout << "(" << setprecision(6) << curr->x << " , ";
	cout << setprecision(5) << curr->y << ")\t";
}

Vector* GPS::getNode(int pos) {
	//Returns a pointer to the node in position 'pos'
	Vector *curr = head;
	//Itterates through the list, until the 'pos'th 
	for (int i = 1; i < pos; i++) {
		curr = curr->next;
	}
	return curr;
}