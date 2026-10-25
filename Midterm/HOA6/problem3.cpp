#include <iostream>

int iterativeBinarySearch(const int arr[], int size, int key) {
    int low = 0;
    int up = size - 1;
    int iteration = 1;

    while (low <= up) {
        int mid = (low + up) / 2;
        std::cout << "Iteration " << iteration++ << ": low=" << low 
                  << ", up=" << up << ", mid=" << mid 
                  << " (arr[mid]=" << arr[mid] << ")\n";

        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "ITERATIVE BINARY SEARCH TRACE\n";
    int result = iterativeBinarySearch(data, size, key);

    if (result != -1) {
        std::cout << "Key " << key << " found at index " << result << ".\n";
    } else {
        std::cout << "Key " << key << " not found.\n";
    }

    return 0;
}