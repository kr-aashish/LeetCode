class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        vector<int> Mex(N+2, 0);
        for(auto x:nums) if(x>=1 and x<=N) Mex[x]++;
        for(int i=1; i<=N; i++) if(!Mex[i]) return i;
        
        return N+1;
    }
};