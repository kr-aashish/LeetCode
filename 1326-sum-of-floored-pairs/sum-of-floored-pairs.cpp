const int N = 100100;
using ll = long long;
int cnt[N], pref[N];
int M = 1e9+7;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        memset(cnt, 0, sizeof(cnt));
        // memset(pref, 0, sizeof(pref));
        
        sort(nums.begin(), nums.end());
        
        for(auto x:nums) cnt[x]++;
        for(int i=1; i<N; i++) {
            pref[i] = cnt[i];
            pref[i] += pref[i-1];
        }
        
        ll ans = 0; 
        for(int i=1; i<N; i++) {
            ll Si = 0;
            for(int j=i; j<N; j+=i) {
                Si += (j/i)*(pref[(j+i-1<N?j+i-1:N-1)]-pref[j-1]);
                Si %= M;
            }
            ans += Si*cnt[i];
            ans %= M;
        }
        
        return ans;
    }
};