class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int countLessThanEqualToLower = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int countLessThanEqualToHigher = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            count += (countLessThanEqualToHigher - countLessThanEqualToLower);
        }

        return count;
    }
};