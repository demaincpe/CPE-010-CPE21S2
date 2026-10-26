#include <iostream>
#include <vector>
#include <algorithm>

int getMinSteps(int n, std::vector<int>& memo) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n]; 

    int r = 1 + getMinSteps(n - 1, memo);
    if (n % 2 == 0) r = std::min(r, 1 + getMinSteps(n / 2, memo));
    if (n % 3 == 0) r = std::min(r, 1 + getMinSteps(n / 3, memo)); 

    memo[n] = r;
    return r;
}

int main() {
    int test_values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 100};
    for (int n : test_values) {
        std::vector<int> memo(n + 1, -1);
        std::cout << "Minimum steps for n = " << n << " : " << getMinSteps(n, memo) << std::endl;
    }
    return 0;
}
