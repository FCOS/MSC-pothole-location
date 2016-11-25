#include "combinedList.h"
#include "Vector.h"

combinedList::combinedList() {
	//default constructor
	head = NULL;
	tail = NULL;
}

void combinedList::addDescending(Vector* node) {
	//Creating a new Vector with the coordinates from GPS, and the z value.
	Vector *newVector = new Vector(node->coordinates->x, node->coordinates->y, node->z);

	if (head == NULL) {
		head = tail = newVector;
	}

	//checking if the new vector is bigger then the head, and if it is,
	//making it the new head
	else if (newVector->z > head->z) {
		newVector->next = head;
		head = newVector;
	}

	else {
		Vector *prev = NULL;
		Vector *curr = head;

		//Itteraet through the list, while the new vector is less then curr
		while (curr != NULL && newVector->z <= curr->z) {
			prev = curr;
			curr = curr->next;
		}

		if (prev != newVector) {
			prev->next = newVector;
			newVector->next = curr;
		}
		if (curr == NULL) {
			tail = newVector;
		}
	}
}

void combinedList::print() {
	//print function
	Vector *curr = head;
	while (curr != NULL) {
		cout << setprecision(6) << "(" << curr->x << ", ";
		cout << setprecision(5) << curr->y << ")\t";
		if (curr->z >= 0) {
			cout << " ";
		}
		cout << curr->z << endl;
		curr = curr->next;
	}
}
