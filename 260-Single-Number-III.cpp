class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long X = 0;
        for(auto x:nums) X ^= x;
        
        long long LSB = X&(~(X-1));
        
        int a = 0, b = 0;
        for(auto x:nums) {
            if(x&LSB) a ^= x;
            else b ^= x;
        }
        
        return {a,b};
    }
};