#include <iostream>
#include <cstdlib>
#include <ctime>

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

    std::cout << "Unsorted Array (100 Elements):\n";
    displayArr(unsortedArr);

    return 0;
}