#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// Iterative Linear Search
int linearSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1; // Worst case: not found
}

// Iterative Binary Search
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Worst case: not found
}

int main() {
    std::vector<int> sizes = {1000, 10000, 100000};
    int target = -1; // Value guaranteed not to be in the dataset (worst-case trigger)

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Input Size (N) | Binary Search (ms) | Linear Search (ms)\n";
    std::cout << "--------------------------------------------------------\n";

    for (int n : sizes) {
        std::vector<int> data(n);
        for (int i = 0; i < n; i++) data[i] = i; // Pre-sorted array

        // Benchmark Linear Search
        auto startLS = std::chrono::high_resolution_clock::now();
        linearSearch(data, target);
        auto endLS = std::chrono::high_resolution_clock::now();
        double timeLS = std::chrono::duration<double, std::milli>(endLS - startLS).count();

        // Benchmark Binary Search
        auto startBS = std::chrono::high_resolution_clock::now();
        binarySearch(data, target);
        auto endBS = std::chrono::high_resolution_clock::now();
        double timeBS = std::chrono::duration<double, std::milli>(endBS - startBS).count();

        std::cout << std::setw(14) << n << " | "
                  << std::setw(18) << timeBS << " | "
                  << std::setw(18) << timeLS << "\n";
    }

    return 0;
}