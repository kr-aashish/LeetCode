const int M = 1e9+7;

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<long long> dp(n+1, 0), sum(n+1, 0), prev(26, 0);
        
        dp[0] = 1, sum[0] = 1; //empty substrings for all!
        
        for(int i=1; i<=n; i++) {
            dp[i] = sum[i-1];
            
            if(prev[s[i-1]-'a']) dp[i] -= sum[prev[s[i-1]-'a']-1];
            prev[s[i-1]-'a'] = i;
            
            sum[i] = sum[i-1] + dp[i];
            sum[i] %= M;
        }
        
        for(int i=1; i<=n; i++) cout<<dp[i]<<" "<<sum[i]<<endl;
        
        return ((sum[n]-1)%M+M)%M;
    }
};