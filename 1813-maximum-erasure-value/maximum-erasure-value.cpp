// https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), result = 0, start = 0, k = 10001;
        vector<int> lastIndexes(k, -1);
        vector<int> prefixSum(n + 1, 0);
        for (int end = 0; end < n; end++) {
            int currentElement = nums[end];
            prefixSum[end + 1] = prefixSum[end] + currentElement;
            if (lastIndexes[currentElement] != -1) {
                start = max(start, lastIndexes[currentElement] + 1);
            }
            // update result with maximum sum found so far
            result = max(result, prefixSum[end + 1] - prefixSum[start]);
            // update last index of current element
            lastIndexes[currentElement] = end;
        }
        return result;
    }
};