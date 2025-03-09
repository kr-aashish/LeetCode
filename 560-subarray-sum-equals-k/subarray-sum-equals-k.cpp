#define f(i,n) for(int i=0; i<n; i++)
using ll = long long;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        vector<ll> p(N);
        
        f(i,N) {
            p[i] = nums[i];
            if(i) p[i] += p[i-1];
        }
        
        map<ll,int> mp; 
        mp[0] = 1;
        ll cnt = 0;
        for(auto sum:p) {
            cnt += mp[sum-k];
            mp[sum]++;
        }
        
        return cnt;
    }
};