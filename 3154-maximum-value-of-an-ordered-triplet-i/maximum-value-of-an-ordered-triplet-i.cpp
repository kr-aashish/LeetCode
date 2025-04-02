// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/?envType=daily-question&envId=2025-04-02
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxElement = 0, maxDiff = 0;
        for (long num : nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return maxTriplet;
    }
};