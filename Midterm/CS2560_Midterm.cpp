// CS2560_Midterm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Class with array of float numbers
//Constructor: Accept array size and dynamically allocate
//Destructor: Free memory held by the array
//Member Functions:
//	Store a number at any element
//	Get a number at any element
//	Return highest value in array
//	Return lowest value in array

#include "pch.h"
#include <iostream>
using namespace std;

class float_array {
	float *theArray = NULL;
	int size = 0;
	public:
		float_array(int array_size) {
			cout << "Creating array of size "<< array_size << ".\n";
			theArray = new float[array_size];

			//Initialize array elements to 0
			for (int i = 0; i < array_size; i++) {
				theArray[i] = 0.0F;
			}

			//Set size variable
			size = array_size;
		}
		~float_array() {
			delete theArray;
		}
		void store(float num, int index) {
			if (index < size) {
				theArray[index] = num;
			}
		}
		float get(int index) {
			if (index < size) {
				return theArray[index];
			}
			else {
				return 0.0F;
			}
		}
		float max() {
			float the_max = theArray[0];
			
			for (int i = 0; i < size; i++) {
				if (theArray[i] > the_max) {
					the_max = theArray[i];
				}
			}

			return the_max;
		}
		float min() {
			float the_min = theArray[0];

			for (int i = 0; i < size; i++) {
				if (theArray[i] < the_min) {
					the_min = theArray[i];
				}
			}

			return the_min;
		}
};

int main()
{
	int array_size = 0;
	cout << "Enter array size: ";
	cin >> array_size;
	float_array *my_array = new float_array(array_size);

	//Store
	cout << "Storing 3.14F at index " << (array_size -1) <<"\n";
	my_array->store(3.14F, (array_size - 1));

	//Get
	cout << "Value at index " << (array_size - 1) << ": ";
	cout << my_array->get(array_size-1) << "\n";

	//Max
	cout << "Max value: ";
	cout << my_array->max() << "\n";

	//Min
	cout << "Min Value: ";
	cout << my_array->min() << "\n";

	delete my_array;
}
