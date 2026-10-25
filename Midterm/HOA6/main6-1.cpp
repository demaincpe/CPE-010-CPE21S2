#include <iostream>
#include <cstdlib>
#include <ctime>

const int max_size = 50;

int main() {
    int dataset[max_size];
    srand(time(0));
    
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}