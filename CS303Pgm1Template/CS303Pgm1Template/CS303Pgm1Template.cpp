// CS303Pgm1Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//NAME: Dylan Gibson
//CS303
//PROGRAM 1

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept> // Sets up input and output as well as strings and exceptions
using namespace std; // Prevents the need to use std::


class DynamicArray { //Handles the creation of the dyanmic array 
private:
    int* data; //Pointer to dynamic array
    int capacity; //Total capacity of array
    int size; // Number of elements in array

    void resize() { //Handles resizing the Array
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int initialCapacity = 50) { //Sets array to a size of 50 to start
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }
    ~DynamicArray() {
        delete[] data; //Deconstructor for data
    }
    int getSize() const { //returns current size of array
        return size;
    }
    int getValue(int index) const { //returns the value of the index
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range");
        return data[index];
    }
    void setValue(int index, int value) { //sets the value of data to the where the index is
        if (index < 0 || index >= size)
            throw out_of_range("Index is out of range");
        data[index] = value;
    }
    void add(int value) { //adds a new point of data and calls resize if size is larger than capacity
        if (size >= capacity)
            resize();
        data[size++] = value; 
    
        void remove(int index) { //Removes specified element in array and moves down elements after the removed elements
            if (index < 0 || index >= size)
                throw out_of_range("Index is out of range");
            for (int i = index; i < size - 1; ++i)
                data[i] = data[i + 1];
            --size;
        }
    int findIndex(int value) const { // returns the index of the specified value, if it can't then it returns -1
        for (int i = 0; i < size; ++i)
            if (data[i] == value)
                return i;
        }
        return -1;
    }
    void printList() const { //Prints all values in the array and moves to the next line
        cout << "The neatly printed array: ";
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
    
};
int main()
{
    std::cout << "Dynamic Arrays\n";
}
