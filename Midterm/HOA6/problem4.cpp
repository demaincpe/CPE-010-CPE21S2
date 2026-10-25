#include <iostream>

int recursiveBinarySearch(const int arr[], int low, int up, int key, int step = 1) {
    // Base Case: Key not found
    if (low > up) {
        return -1;
    }

    int mid = low + (up - low) / 2;

    std::cout << "Recursion Level " << step << ": low=" << low 
              << ", up=" << up << ", mid=" << mid 
              << " (arr[mid]=" << arr[mid] << ")\n";

    // Base Case: Key found
    if (arr[mid] == key) {
        return mid;
    }

    // Recursive Call: Left Sub-array
    if (key < arr[mid]) {
        return recursiveBinarySearch(arr, low, mid - 1, key, step + 1);
    }

    // Recursive Call: Right Sub-array
    return recursiveBinarySearch(arr, mid + 1, up, key, step + 1);
}

int main() {
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "RECURSIVE BINARY SEARCH TRACE\n";
    int result = recursiveBinarySearch(data, 0, size - 1, key);

    if (result != -1) {
        std::cout << "Key " << key << " found at index " << result << ".\n";
    } else {
        std::cout << "Key " << key << " not found.\n";
    }

    return 0;
}