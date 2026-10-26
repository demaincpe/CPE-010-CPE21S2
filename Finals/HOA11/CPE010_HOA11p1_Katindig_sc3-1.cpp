#include <iostream>
#include <chrono>
using namespace std;

// Linear Recursive Power
double rpower(double x, int n) {
    if (n == 0) return 1;              
    else return x * rpower(x, n - 1);  
}

// Binary Recursive Power
double brpower(double x, int n) {
    if (n == 0) return 1;             
    if (n % 2 != 0) {                  
        double y = brpower(x, (n - 1) / 2); 
        return x * y * y;              
    } else {                           
        double y = brpower(x, n / 2);  
        return y * y;                  
    }
}

int main() {
    double x = 1.0001;
    int sizes[] = {10, 1000, 10000};

    for (int n : sizes) {
        // Measure rpower
        auto start1 = chrono::high_resolution_clock::now();
        double res1 = rpower(x, n);
        auto end1 = chrono::high_resolution_clock::now();
        auto time1 = chrono::duration<double, nano>(end1 - start1).count();

        // Measure brpower
        auto start2 = chrono::high_resolution_clock::now();
        double res2 = brpower(x, n);
        auto end2 = chrono::high_resolution_clock::now();
        auto time2 = chrono::duration<double, nano>(end2 - start2).count();

        cout << "n = " << n << ":\n";
        cout << "  rpower  | Time: " << time1 << " ns\n";
        cout << "  brpower | Time: " << time2 << " ns\n\n";
    }

    return 0;
}