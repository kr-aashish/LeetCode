// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/?envType=daily-question&envId=2025-07-17
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int num : nums) {
            num %= k;
            for (int prev = 0; prev < k; ++prev) {
                dp[prev][num] = dp[num][prev] + 1;
                res = max(res, dp[prev][num]);
            }
        }
        return res;
    }
};