#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <utility> // for std::swap
#include <cstddef>

// A.1 Bubble Sort
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

// A.2 Selection Sort Helper
template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position = K;
    T smallestElem = A[K];

    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

// A.2 Selection Sort
template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, pass = 0;
    T temp;

    for (int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}

// A.3 Insertion Sort
template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J;
    T temp;

    while (K < N) {
        temp = arr[K];
        J = K - 1;

        // J >= 0 boundary check prevents out-of-bounds crash
        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

#endif