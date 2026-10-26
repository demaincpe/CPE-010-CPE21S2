#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

// Optimized Bubble Sort (Linear best-case via swap flag)
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Standard Merge routine
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
}

// Recursive Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> sizes = {100, 1000, 10000};
    std::cout << std::fixed << std::setprecision(4);

    // =======================================================
    // 1. BUBBLE SORT BENCHMARKS
    // =======================================================
    std::cout << "====================================================\n";
    std::cout << "             ALGORITHM 1: BUBBLE SORT               \n";
    std::cout << "====================================================\n";

    std::cout << "\n--- [BEST CASE: Already Sorted Array - O(n)] ---\n";
    for (int n : sizes) {
        std::vector<int> b_best(n);
        for (int i = 0; i < n; i++) b_best[i] = i;

        auto t1 = std::chrono::high_resolution_clock::now();
        bubbleSort(b_best);
        auto t2 = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration<double, std::milli>(t2 - t1).count();

        std::cout << "N = " << std::setw(6) << std::left << n 
                  << " | Elapsed Time: " << std::setw(10) << std::right << elapsed << " ms\n";
    }

    std::cout << "\n--- [WORST CASE: Reverse Sorted Array - O(n^2)] ---\n";
    for (int n : sizes) {
        std::vector<int> b_worst(n);
        for (int i = 0; i < n; i++) b_worst[i] = n - i;

        auto t1 = std::chrono::high_resolution_clock::now();
        bubbleSort(b_worst);
        auto t2 = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration<double, std::milli>(t2 - t1).count();

        std::cout << "N = " << std::setw(6) << std::left << n 
                  << " | Elapsed Time: " << std::setw(10) << std::right << elapsed << " ms\n";
    }

    // =======================================================
    // 2. MERGE SORT BENCHMARKS
    // =======================================================
    std::cout << "\n====================================================\n";
    std::cout << "              ALGORITHM 2: MERGE SORT               \n";
    std::cout << "====================================================\n";

    std::cout << "\n--- [BEST CASE: Already Sorted Array - O(n log n)] ---\n";
    for (int n : sizes) {
        std::vector<int> m_best(n);
        for (int i = 0; i < n; i++) m_best[i] = i;

        auto t1 = std::chrono::high_resolution_clock::now();
        mergeSort(m_best, 0, n - 1);
        auto t2 = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration<double, std::milli>(t2 - t1).count();

        std::cout << "N = " << std::setw(6) << std::left << n 
                  << " | Elapsed Time: " << std::setw(10) << std::right << elapsed << " ms\n";
    }

    std::cout << "\n--- [WORST CASE: Reverse Sorted Array - O(n log n)] ---\n";
    for (int n : sizes) {
        std::vector<int> m_worst(n);
        for (int i = 0; i < n; i++) m_worst[i] = n - i;

        auto t1 = std::chrono::high_resolution_clock::now();
        mergeSort(m_worst, 0, n - 1);
        auto t2 = std::chrono::high_resolution_clock::now();
        double elapsed = std::chrono::duration<double, std::milli>(t2 - t1).count();

        std::cout << "N = " << std::setw(6) << std::left << n 
                  << " | Elapsed Time: " << std::setw(10) << std::right << elapsed << " ms\n";
    }

    std::cout << "====================================================\n";
    return 0;
}