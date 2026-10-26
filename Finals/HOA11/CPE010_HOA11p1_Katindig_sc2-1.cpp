#include <iostream>
#include <chrono>

using namespace std;

// Algorithm Unique using two nested loops
bool Unique(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}

int main() {
    int A1[] = {10, 20, 30, 40, 50, 60};        // Case A: All unique (Worst Case)
    int A2[] = {99, 99, 20, 30, 40, 50};        // Case B: Duplicate at start (Best Case)
    int A3[] = {10, 20, 30, 40, 50, 60, 30};    // Case C: Duplicate near end

    // Measure Case A
    auto start1 = chrono::high_resolution_clock::now();
    bool res1 = Unique(A1, 6);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> time1 = end1 - start1;

    // Measure Case B
    auto start2 = chrono::high_resolution_clock::now();
    bool res2 = Unique(A2, 6);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> time2 = end2 - start2;

    // Measure Case C
    auto start3 = chrono::high_resolution_clock::now();
    bool res3 = Unique(A3, 7);
    auto end3 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> time3 = end3 - start3;

    // Output Results
    cout << "Case A: " << (res1 ? "Unique" : "Not Unique") 
         << " | Execution Time: " << time1.count() << " ns" << endl;

    cout << "Case B: " << (res2 ? "Unique" : "Not Unique") 
         << " | Execution Time: " << time2.count() << " ns" << endl;

    cout << "Case C: " << (res3 ? "Unique" : "Not Unique") 
         << " | Execution Time: " << time3.count() << " ns" << endl;

    return 0;
}