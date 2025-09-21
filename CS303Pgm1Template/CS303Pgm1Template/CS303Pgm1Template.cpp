// CS303Pgm1Template.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//
//NAME: Dylan Gibson
//CS303
//PROGRAM 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <stdexcept> // Sets up input and output as well as strings and exceptions

#include "DynamicArray.h" //Includes the header

using namespace std; // Prevents the need to use std::

bool isNumber(const string& str) { //Checks if the string is a valid integer
	istringstream iss(str);
	int val;
	return (iss >> val) && (iss.eof());
}

int getValidIndex(int max) { //Asks user for a valid index until provided
	int index;
	while (true) {
		cout << "Enter index (0 to " << max - 1 << "): ";
		cin >> index;
		if (cin.fail() || index < 0 || index >= max) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid index. Try again.\n";
		} 
		else {
			return index;
		}
	}
}
int getValidNumber() { //Asks user for a valid integer until provided
	int value;
	while (true) {
		cout << "Enter a number: ";
		cin >> value;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invaild input. Must be a number.\n";
		} 
		else {
			return value;
		}
	}
}
void loadFile(DynamicArray& arr, const string& filename, const string& errorFile) {
	//reads from the file line by line and adds it to the array, writes to error.txt if it can't 
	ifstream infile(filename);
	ofstream errorOut(errorFile); // Overwrites file each run
	string line;

	while (getline(infile, line)) {
		istringstream iss(line);
		string token;
		while (iss >> token) {
			try {
				if (!isNumber(token))
					throw runtime_error("Input isn't a number");

				int value = stoi(token);
				arr.add(value);
			}
			catch (exception& e) {
				errorOut << "Error: " << e.what() << " -> " << line << endl;
			}
		}
	}
	infile.close();
	errorOut.close();
}

void menu() { //Provides the options for the user menu.
	cout << "\n--- THE MENU ---\n";
	cout << "Please type 1 to 6 to select an option\n";
	cout << "1. Find a value in the list\n";
	cout << "2. Modify a value in the list\n";
	cout << "3. Add a value to the list\n";
	cout << "4. Delete a value in the list\n";
	cout << "5. Print the contents of the array\n";
	cout << "6. Exit\n";
}

int main() { //initializes the dynamic array and loads it with the input file
	DynamicArray array;
	loadFile(array, "A1input.txt", "error.txt");

	int choice; //Depending on what number from 1 to 6 the user types, the program will do the following
	while (true) {//Before any modifications are made the following will loop until the user "exits" with option 6
		menu(); //prints the user menu with error handling if number is not valid
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Try again.\n";
			continue;
		}
		switch (choice) {
		case 1: { //Finds value in array
			int value = getValidNumber();
			int index = array.findIndex(value);
			if (index != -1)
				cout << "Value found at index: " << index << endl;
			else
				cout << "Value not found.\n";
			break;
		}
		case 2: {//Modifies value in array
			int index = getValidIndex(array.getSize());
			int newValue = getValidNumber();
			try {
				int oldValue = array.getValue(index);
				array.setValue(index, newValue);
				cout << "Updated index " << index << " from " << oldValue << " to " << newValue << endl;
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		}
		case 3: {//adds value to array
			int value = getValidNumber();
			array.add(value);
			cout << "Value added.\n";
			break;;
		}
		case 4: {//deletes value from array
			int index = getValidIndex(array.getSize());
			try {
				array.remove(index);
				cout << "Value removed.\n";
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		}
		case 5: {//prints entire array
			array.printList();
			break;
		}
		case 6: {//exits program loop
			cout << "Exiting program.\n";
			return 0;
		}
		default://If user picks none of these options then prints this line
			cout << "Invalid choice. Try again.\n";
		}
	}
}
//have a good day!!! :)