// main.cpp for Table 6-3a
#include <iostream>
#include "searching6-3a.h"

int main() {
    // Binary search requires a strictly sorted array
    int sortedData[] = {3, 7, 12, 18, 24, 31, 45, 53, 67, 89};
    int size = sizeof(sortedData) / sizeof(sortedData[0]);

    std::cout << "Array: ";
    for (int i = 0; i < size; i++) std::cout << sortedData[i] << " ";
    std::cout << "\n";

    binarySearch(size, 45, sortedData);
    binarySearch(size, 67, sortedData);
    binarySearch(size, 80, sortedData);

    return 0;
}