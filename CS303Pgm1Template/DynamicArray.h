//NAME: Dylan Gibson
//CS303
//PROGRAM 1
//Header File
class DynamicArray {
private:
    int* data; //Pointer to dynamic array
    int capacity; //Total capacity of array
    int size; //Number of elements in array

    void resize(); //method to double capacity when called

public:
    DynamicArray(int initialCapacity = 50); //Sets array to size of 
    ~DynamicArray(); //Destructor
    int getSize() const; //Gets size
    int getValue(int index) const; //Gets value
    void setValue(int index, int value); //Sets value
    void add(int value); //Adds element
    void remove(int index); //Removes element
    int findIndex(int value) const; //Finds index of value
    void printList() const; //Prints array
};