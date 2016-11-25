#include <iostream>
#include <cmath>
#include <Windows.h>
#include "Vector.h"
#include "GPS.h"
#include "sensor.h"
#include "combinedList.h"
using namespace std;

void main() {
	int threshold, size = 1, i = 1;

	//Getting the user to input the threshold for what is to be deemed a pothole.
	cout << "Z-axis acceleration threshold? ";
	cin >> threshold;


	//Constructing the linked lists that will be used in this programme
	sensor* acceleration = new sensor();
	GPS* location = new GPS();
	combinedList* sortedList = new combinedList();


	//Filling the GPS and Sensor linke lists. NOTE: This could be much more efficient if
	//I were to add all the coordinates at once, however I am instead adding one set of
	//coordinates or sensor values into the linked list each time the loop runs, to
	//better reneact the device finding a new location every second.

	while (acceleration->eof != true) {
		location->getLocation(size);
		acceleration->getAcceleration(size);

		//If we have reached the end of file, there are no more values to print, so we break.
		if (acceleration->eof == true) {
			break;
		}

		//Printing the coordinates, and their respective 'z' values only.
		location->print(size);
		acceleration->printZ(size);
		cout << endl;
		size++;

		//This creates a second delay between each time the programme reads a 
		//location from the file. UnComment it for delay.
		//Sleep(1000); 
	}

	//Finding the average of the z values, and printing it out
	cout << endl << "The average Z value is " << acceleration->getAverageZ() << "\n\n";
	

	//adding the values over the threshold to a new linked list.
	while (location->getNode(i)->next != NULL) {

		if (abs(acceleration->getNode(i)->z) >= threshold) {


			//My section, which differentiates between rises (bumps) and dips (potholes).
			if (abs(acceleration->getNode(i)->next->z) >= threshold && abs(acceleration->getNode(i)->next->z) >= 10) {

				if (acceleration->getNode(i)->z > acceleration->getNode(i)->next->z) {
					cout << "(" << setprecision(6) << location->getNode(i)->x << ", ";
					cout << setprecision(5) << location->getNode(i)->y << ") \tThis is a bump.\n";
				}
				else {
					cout << "(" << setprecision(6) << location->getNode(i)->x << ", ";
					cout << setprecision(5) << location->getNode(i)->y << ") \tThis is a pothole.\n";
				}
			}

			//If the z value is over the threshold, then it is linked via the coordinates pointer,
			//to its corresponding coordinates vector.
			acceleration->getNode(i)->coordinates = location->getNode(i);
			//If the z value is over the threshold, it is added to a new linked list, comprising of
			//the coordinates and the z value only. It is soreted in descending order of magnitude,
			//from positive to negative, rather than by absolute value. To sort it using absolute value,
			//I would simply add the abs() function.
			sortedList->addDescending(acceleration->getNode(i));
		}
		i++;
	}

	//Printing values over the threshold
	cout << "\nLocations and acceleration vector z of potholes:\n";
	sortedList->print();

	//This line is to keep the console open, when run using the .exe
	system("pause");

	return;
}
