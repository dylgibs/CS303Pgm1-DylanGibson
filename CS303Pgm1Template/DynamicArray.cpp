//NAME: Dylan Gibson
//CS303
//PROGRAM 1
//Dynamic Array.cpp File
#include "DynamicArray.h"
#include <iostream>
#include <stdexcept> // includes header file and basic libaries

using namespace std; //Removes the need to use std::

DynamicArray::DynamicArray(int initialCapacity) { //sets size to 0 and allocates memory
	capacity = initialCapacity;
	size = 0;
	data = new int[capacity];
}

DynamicArray::~DynamicArray() { //acts as destructor when called
	delete[] data;
}

void DynamicArray::resize() { //Resizes the array by doubling the capacity and copies the old data
	capacity *= 2;
	int* newData = new int[capacity];
	for (int i = 0; i < size; ++i)
		newData[i] = data[i];
	delete[] data; //Deletes the old array 
	data = newData; //Sets new array to old array
}

int DynamicArray::getSize() const { //returns the size
	return size;
}
int DynamicArray::getValue(int index) const { //returns the value of the index or throws an error if it is out of range
	if (index < 0 || index >= size)
		throw out_of_range("Index is out of range");
	return data[index];
}

void DynamicArray::setValue(int index, int value) { //sets data at a specificied index to a new value or throws an error
	if (index < 0 || index >= size)
		throw out_of_range("Index is out of range");
	data[index] = value;
}

void DynamicArray::add(int value) { //doubles the size of array if size is greater than capacity and then adds a new value to the end of array 
	if (size >= capacity)
		resize();
	data[size++] = value;
}

void DynamicArray::remove(int index) { //Removes value and shifts array size down 1
	if (index < 0 || index >= size)
		throw out_of_range("Index is out of range");
	for (int i = index; i < size - 1; ++i)
		data[i] = data[i + 1];
	--size;
}
int DynamicArray::findIndex(int value) const { //Returns index of a specificied value or -1 if it can't
	for (int i = 0; i < size; ++i)
		if (data[i] == value)
			return i;
	return -1;
}
void DynamicArray::printList() const { //Prints each element of the array
	cout << "The neatly printed array: ";
	for (int i = 0; i < size; ++i)
		cout << data[i] << " ";
	cout << endl;
}
