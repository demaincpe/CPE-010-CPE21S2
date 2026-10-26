#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int max_size = 100;

void displayArr(int arr[]); // matched signature

int main() {
    int unsortedArr[max_size];
    srand(time(0));

    for (int i = 0; i < max_size; i++) {
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "unsortedArr:\n";
    displayArr(unsortedArr);

    std::cout << "\ninsertion sort:\n";
    insertionSort(unsortedArr, max_size);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < max_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}