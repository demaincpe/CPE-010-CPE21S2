#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    int originalArr[maxSize];
    int arrBubble[maxSize];
    int arrSelection[maxSize];
    int arrInsertion[maxSize];

    srand(time(0));

    // Populate the original array and copy to test arrays
    for (int i = 0; i < maxSize; i++) {
        originalArr[i] = rand() % 100;
        arrBubble[i] = originalArr[i];
        arrSelection[i] = originalArr[i];
        arrInsertion[i] = originalArr[i];
    }

    // Table 7-1: Preparation Task
    std::cout << "Table 7-1: Original Unsorted Array" << std::endl;
    displayArr(originalArr);

    // Table 7-2: Bubble Sort
    std::cout << "Table 7-2: Bubble Sort Output" << std::endl;
    bubbleSort(arrBubble, maxSize);
    displayArr(arrBubble);

    // Table 7-3: Selection Sort
    std::cout << "Table 7-3: Selection Sort Output" << std::endl;
    selectionSort(arrSelection, maxSize);
    displayArr(arrSelection);

    // Table 7-4: Insertion Sort
    std::cout << "Table 7-4: Insertion Sort Output" << std::endl;
    insertionSort(arrInsertion, maxSize);
    displayArr(arrInsertion);

    return 0;
}