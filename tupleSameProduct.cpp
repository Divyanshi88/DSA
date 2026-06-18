#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size(), result = 0;

        // Count product frequencies
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Compute the number of tuples
        for (auto& [product, freq] : productCount) {
            if (freq > 1) {
                result += (freq * (freq - 1) / 2) * 8; // Each valid pair contributes 8 tuples
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 4, 6};
    vector<int> nums2 = {1, 2, 4, 5, 10};

    cout << sol.tupleSameProduct(nums1) << endl;  // Output: 8
    cout << sol.tupleSameProduct(nums2) << endl;  // Output: 16
    return 0;
}
