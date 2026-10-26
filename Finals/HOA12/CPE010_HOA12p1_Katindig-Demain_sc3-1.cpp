#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define M 4
#define N 4

// Dynamic Programming with Memoization using an unordered_map key
int countPaths(int mat[M][N], int m, int n, int cost, std::unordered_map<std::string, int>& dp) {
    if (m < 0 || n < 0 || cost < 0) {
        return 0;
    }

    if (m == 0 && n == 0) {
        return (mat[0][0] == cost) ? 1 : 0;
    }

    std::string key = std::to_string(m) + "|" + std::to_string(n) + "|" + std::to_string(cost);
 
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

 
    int pathsFromTop = countPaths(mat, m - 1, n, cost - mat[m][n], dp);
    int pathsFromLeft = countPaths(mat, m, n - 1, cost - mat[m][n], dp);

    dp[key] = pathsFromTop + pathsFromLeft;
    return dp[key];
}

int main() {
    int mat[M][N] = {
        { 4, 7, 1, 6 },
        { 6, 7, 3, 9 },
        { 3, 8, 1, 2 },
        { 7, 1, 7, 3 }
    };

    std::cout << "--- Count Paths in Matrix with Given Cost ---" << std::endl;
    std::cout << "Matrix Size: " << M << " x " << N << std::endl;

    // Test with cost = 26 
    std::unordered_map<std::string, int> dp26;
    int target_cost1 = 26;
    int result1 = countPaths(mat, M - 1, N - 1, target_cost1, dp26);
    std::cout << "Total number of paths with cost " << target_cost1 
              << " (highlighted path): " << result1 << std::endl;

    // Test with cost = 25
    std::unordered_map<std::string, int> dp25;
    int target_cost2 = 25;
    int result2 = countPaths(mat, M - 1, N - 1, target_cost2, dp25);
    std::cout << "Total number of paths with cost " << target_cost2 
              << " (prompt text): " << result2 << std::endl;

    return 0;
}
