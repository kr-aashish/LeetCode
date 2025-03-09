class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        
        for(int len=1; len<=n; len++) {
            for(int l=0; l<n; l++) {
                int r = l+len-1;
                if(r>=n) break;
                
                if(len==1) dp[l][r] = 1;
                else if(len==2) dp[l][r] = s[l]==s[r];
                else dp[l][r] = (s[l]==s[r]) and dp[l+1][r-1];
                
                ans += dp[l][r];
            }
        }
        
        return ans;
    }
};