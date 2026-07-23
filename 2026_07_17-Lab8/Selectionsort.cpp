/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

// Arrange the array in ascending order using Selection Sort
void sortSelection(int numbers[], int size) {

    for (int start = 0; start < size - 1; start++) {

        // Assume the first unsorted element is the smallest
        int smallest = start;

        // Search for a smaller value in the remaining elements
        for (int current = start + 1; current < size; current++) {

            if (numbers[current] < numbers[smallest]) {
                smallest = current;
            }
        }

        // Exchange the smallest value with the current position
        if (smallest != start) {
            swap(numbers[start], numbers[smallest]);
        }
    }
}

// Display all elements in the array
void displayArray(int numbers[], int size) {

    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    cout << endl;
}

int main() {

    // Sample data
    int numbers[] = {81, 25, 63, 14, 97, 38, 52};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Before Selection Sort: ";
    displayArray(numbers, size);

    sortSelection(numbers, size);

    cout << "After Selection Sort: ";
    displayArray(numbers, size);

    return 0;
}