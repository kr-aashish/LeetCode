// https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i) {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i) {
            nums[i] /= 1000;
        }
        return nums;
    }
};