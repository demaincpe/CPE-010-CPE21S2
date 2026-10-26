#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int unsortedArr[maxSize];
    srand(time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }
    // Table 8-1. Array of Values for Sort Algorithm Testing
    std::cout << "Original Unsorted Array (100 Elements):\n";
    displayArr(unsortedArr);

    // Table 8-2. Shell Sort
    std::cout << "\nShell Sort Output:\n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    // Table 8-3. Merge Sort 
    std::cout << "\nMerge Sort Output:\n";
    mergeSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    // Table 8-4. Quick Sort
    std::cout << "\nQuick Sort Output:\n";
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    return 0;
}