class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CurrentSum = nums[0];
        int maxSum = nums[0];
        for(int i =1; i<nums.size(); i++){
            CurrentSum = max(nums[i], CurrentSum+nums[i]);
            maxSum= max(maxSum, CurrentSum);
        }
        return maxSum;
    }
};
