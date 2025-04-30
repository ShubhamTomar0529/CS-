#include <iostream>
using namespace std;

// Global variables
int* arrayList = nullptr; // Pointer to the dynamic array
int currentSize = 0;      // Current number of elements
int capacity = 0;         // Total allocated size

// Function to initialize the array list
void initializeArrayList(int initialCapacity) {
    capacity = initialCapacity;
    currentSize = 0;
    arrayList = new int[capacity];
}

// Function to resize the array when it's full
void resizeArrayList() {
    capacity *= 2; // Double the capacity
    int* newArray = new int[capacity];

    // Copy elements to the new array
    for (int i = 0; i < currentSize; ++i) {
        newArray[i] = arrayList[i];
    }

    // Delete the old array and assign the new one
    delete[] arrayList;
    arrayList = newArray;
}

// Function to insert an element at the end
void insertElement(int element) {
    if (currentSize == capacity) {
        resizeArrayList(); // Resize if the array is full
    }
    arrayList[currentSize++] = element; // Add the element and increment size
}

// Function to delete an element at a specific index
void deleteElement(int index) {
    if (index < 0 || index >= currentSize) {
        cout << "Index out of bounds!" << endl;
        return;
    }

    // Shift elements to the left to overwrite the deleted element
    for (int i = index; i < currentSize - 1; ++i) {
        arrayList[i] = arrayList[i + 1];
    }

    currentSize--; // Reduce the size
}

// Function to search for an element and return its index
int searchElement(int element) {
    for (int i = 0; i < currentSize; ++i) {
        if (arrayList[i] == element) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to clean up memory
void deleteArrayList() {
    delete[] arrayList;
    arrayList = nullptr;
    currentSize = 0;
    capacity = 0;
}

int main() {
    // Example usage
    initializeArrayList(2); // Start with a capacity of 2

    insertElement(10);
    insertElement(20);
    insertElement(30); // Triggers resizing

    cout << "Array list after insertions: ";
    for (int i = 0; i < currentSize; ++i) {
        cout << arrayList[i] << " ";
    }
    cout << endl;

    deleteElement(1); // Delete the element at index 1

    cout << "Array list after deletion: ";
    for (int i = 0; i < currentSize; ++i) {
        cout << arrayList[i] << " ";
    }
    cout << endl;

    int searchKey = 30;
    int index = searchElement(searchKey);
    if (index != -1) {
        cout << "Element " << searchKey << " found at index " << index << endl;
    } else {
        cout << "Element " << searchKey << " not found!" << endl;
    }

    deleteArrayList(); // Clean up memory
    return 0;
}
