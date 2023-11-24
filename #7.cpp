#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <algorithm>

int maxSumSubsequence(const std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        int maxSum = INT_MIN;
        for (int j = std::max(0, i - k); j < i; ++j) {
            maxSum = std::max(maxSum, dp[j]);
        }
        dp[i] = std::max(nums[i], nums[i] + maxSum);
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums1 = { 10, 2, -10, 5, 20 };
    int k1 = 2;
    std::cout << "Output 1: " << maxSumSubsequence(nums1, k1) << std::endl;

    std::vector<int> nums2 = { -1, -2, -3 };
    int k2 = 1;
    std::cout << "Output 2: " << maxSumSubsequence(nums2, k2) << std::endl;

    std::vector<int> nums3 = { 10, -2, -10, -5, 20 };
    int k3 = 2;
    std::cout << "Output 3: " << maxSumSubsequence(nums3, k3) << std::endl;

    return 0;
}
