class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLength = 1;
        int decLength = 1;
        int longestIncLength = 1;
        int longestDecLength = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                incLength++;
                decLength = 1;
                longestIncLength = max(longestIncLength, incLength);
            } else if (nums[i] < nums[i - 1]) {
                decLength++;
                incLength = 1;
                longestDecLength = max(longestDecLength, decLength);
            } else {
                incLength = 1;
                decLength = 1;
            }
        }

        return max(longestIncLength, longestDecLength);
    }
};