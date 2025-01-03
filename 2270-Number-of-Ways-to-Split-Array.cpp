class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (auto num : nums) {
            totalSum += num;
        }

        int count = 0;
        long long prevSum = 0;
        for (int i = 0; i < int(nums.size()) - 1; i++) {
            prevSum += nums[i];
            if (prevSum >= totalSum - prevSum) {
                count++;
            }
        }

        return count;
    }
};