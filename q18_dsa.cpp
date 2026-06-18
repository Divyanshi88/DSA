#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubArray(nums) << std::endl;
    return 0;
}
