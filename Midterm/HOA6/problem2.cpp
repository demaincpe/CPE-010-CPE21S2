#include <iostream>

int countOccurrences(const int arr[], int size, int k) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == k) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int k = 18;

    int totalCount = countOccurrences(data, size, k);
    std::cout << "Element " << k << " appears " << totalCount << " time(s) in the dataset.\n";

    return 0;
}