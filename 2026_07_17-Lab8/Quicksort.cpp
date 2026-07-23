/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

// Rearrange the array around the pivot
int divideArray(int numbers[], int start, int end) {

    int pivot = numbers[start];   // First element is chosen as the pivot
    int left = start + 1;
    int right = end;

    while (left <= right) {

        // Find the first value greater than the pivot
        while (left <= end && numbers[left] < pivot)
            left++;

        // Find the first value smaller than the pivot
        while (right > start && numbers[right] > pivot)
            right--;

        // Swap the two values if they have not crossed
        if (left < right) {
            swap(numbers[left], numbers[right]);
            left++;
            right--;
        }
    }

    // Put the pivot into its correct position
    swap(numbers[start], numbers[right]);

    return right;
}

// Apply Quick Sort recursively
void quickSort(int numbers[], int start, int end) {

    if (start >= end)
        return;

    int pivotIndex = divideArray(numbers, start, end);

    quickSort(numbers, start, pivotIndex - 1);
    quickSort(numbers, pivotIndex + 1, end);
}

// Print the array
void printArray(int numbers[], int size) {

    for (int i = 0; i < size; i++)
        cout << numbers[i] << " ";

    cout << endl;
}

int main() {

    // Different set of values
    int numbers[] = {42, 17, 93, 8, 61, 29, 74, 55};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original Array: ";
    printArray(numbers, size);

    quickSort(numbers, 0, size - 1);

    cout << "Sorted Array: ";
    printArray(numbers, size);

    return 0;
}