#include <iostream>
#include <vector>
#include <algorithm>

int getMinSteps(int n) {
    std::vector<int> dp(n + 1);
    dp[1] = 0; 

    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1]; 
        if (i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]); 
        if (i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]); 
    }
    return dp[n];
}

int main() {
    int test_values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 100};
    for (int n : test_values) {
        std::cout << "Minimum steps for n = " << n << " : " << getMinSteps(n) << std::endl;
    }
    return 0;
}
