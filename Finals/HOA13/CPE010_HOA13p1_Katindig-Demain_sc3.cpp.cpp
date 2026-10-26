#include <iostream>
#include <thread>
#include <chrono>

// Global variable requirement
int global_counter = 0;

// Add function taking an integer parameter
void add(int value) {
    // Small artificial delay to highlight asynchronous lifecycle
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    global_counter += value;
}

int main() {
    std::cout << "=== Part B: Multithreading with Stepwise Join ===" << std::endl;

    // Create 3 threads passing the add function individually
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // Exact required execution & display sequence
    std::cout << "[Initial] Global Value: " << global_counter << std::endl; //
    
    T1.join(); //
    std::cout << "[After T1.join()] Global Value: " << global_counter << std::endl; //
    
    T2.join(); //
    std::cout << "[After T2.join()] Global Value: " << global_counter << std::endl; //[cite: 85]
    
    T3.join(); //[cite: 85]
    std::cout << "[After T3.join()] Global Value: " << global_counter << std::endl; //[cite: 85]

    return 0;
}