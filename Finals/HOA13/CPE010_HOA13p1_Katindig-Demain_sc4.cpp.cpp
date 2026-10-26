#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm>

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

// Sequential Merge Sort
void sequentialMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    sequentialMergeSort(arr, left, mid);
    sequentialMergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Multithreaded Merge Sort (Depth-limited to avoid excessive thread overhead)
void parallelMergeSort(std::vector<int>& arr, int left, int right, int depth = 0) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Use multithreading only at the top levels (depth < 2 -> spawns up to 4 threads)
    if (depth < 2) {
        std::thread leftThread(parallelMergeSort, std::ref(arr), left, mid, depth + 1);
        std::thread rightThread(parallelMergeSort, std::ref(arr), mid + 1, right, depth + 1);

        leftThread.join();
        rightThread.join();
    } else {
        // Fall back to sequential sorting when subproblems become small
        sequentialMergeSort(arr, left, mid);
        sequentialMergeSort(arr, mid + 1, right);
    }

    merge(arr, left, mid, right);
}

int main() {
    const int N = 1000000; // 1,000,000 elements
    std::cout << "=== Part C: Multithreaded Merge Sort vs Sequential ===" << std::endl;
    std::cout << "Dataset Size: " << N << " integers\n" << std::endl;

    // Generate random dataset
    std::vector<int> data1(N);
    std::mt19937 rng(1337);
    for (int i = 0; i < N; ++i) data1[i] = rng() % 10000000;
    std::vector<int> data2 = data1; // Exact replica for fair comparison

    // Benchmark Sequential Merge Sort
    auto t1 = std::chrono::high_resolution_clock::now();
    sequentialMergeSort(data1, 0, N - 1);
    auto t2 = std::chrono::high_resolution_clock::now();
    double seq_time = std::chrono::duration<double, std::milli>(t2 - t1).count();
    std::cout << "Sequential Merge Sort: " << seq_time << " ms" << std::endl;

    // Benchmark Multithreaded Merge Sort
    auto t3 = std::chrono::high_resolution_clock::now();
    parallelMergeSort(data2, 0, N - 1);
    auto t4 = std::chrono::high_resolution_clock::now();
    double par_time = std::chrono::duration<double, std::milli>(t4 - t3).count();
    std::cout << "Parallel Merge Sort:   " << par_time << " ms" << std::endl;

    std::cout << "\nSpeedup: " << seq_time / par_time << "x faster" << std::endl;
    return 0;
}