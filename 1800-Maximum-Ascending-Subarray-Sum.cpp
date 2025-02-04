class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currentSum = nums[0];
        int maximumSum = currentSum;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                currentSum = nums[i];
            }
            maximumSum = max(maximumSum, currentSum);
        }

        return maximumSum;
    }
};