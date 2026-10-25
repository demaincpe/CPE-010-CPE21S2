// main.cpp for Table 6-2a
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searching.h"

const int max_size = 50;

int main() {
    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand() % 100; // Limited to 0-99 for easier testing
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n";

    int choice;
    std::cout << "what number to find: ";
    std::cin >> choice;

    linearSearch(max_size, choice, dataset);
    return 0;
}