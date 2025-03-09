class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxTillNow = INT_MIN; 
        for(auto x:nums) {
            curr += x; 
            maxTillNow = max(maxTillNow, curr);
            if(curr<0) curr = 0;
        }
        return maxTillNow;
    }
};