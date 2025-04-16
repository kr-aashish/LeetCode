class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxValue = 0;
        int maxDiff = 0;    
        long long maxTripletValue = 0;

        for (int k = 0; k < nums.size(); k++) {
            maxTripletValue = max(maxTripletValue, 1LL * maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxValue - nums[k]);
            maxValue = max(maxValue, nums[k]);
        }

        return maxTripletValue;
    }
};