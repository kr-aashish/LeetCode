class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len=1; len<=n; len++) {
            for(int l=0; l<n; l++) {
                int r = l+len-1;
                if(r>=n) break;
                
                if(len==1) dp[l][r] = 0;
                else if(len==2) {
                    if(s[l]==s[r]) dp[l][r] = 0;
                    else dp[l][r] = 1;
                }
                else {
                    if(s[l]==s[r]) dp[l][r] = dp[l+1][r-1];
                    else {
                        dp[l][r] = min(dp[l+1][r], dp[l][r-1]) + 1;
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};