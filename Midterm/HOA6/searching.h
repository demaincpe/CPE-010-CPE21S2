// searching.h for Table 6-2a
#ifndef SEARCHING_H
#define SEARCHING_H
#include <iostream>

template <typename T>
void linearSearch(int size, T dataFind, T array[]) {
    for (int i = 0; i < size; i++) {
        if (array[i] == dataFind) {
            std::cout << "Searching is successful\n";
            return;
        }
    }
    std::cout << "Searching is Unsuccessful\n";
}
#endif