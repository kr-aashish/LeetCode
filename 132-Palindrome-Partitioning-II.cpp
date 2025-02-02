class Solution {
    
    vector<vector<int>> getPalindromicSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len=1; len<=n; len++) {
            for(int l=0; l<n; l++) {
                int r = l+len-1;
                if(r>=n) break;
                
                if(len==1) dp[l][r] = 1;
                else if(len==2) dp[l][r] = s[l]==s[r];
                // else dp[l][r] = (s[l]==s[r]) and dp[l-1][r-1];
                else dp[l][r] = (s[l]==s[r]) and dp[l+1][r-1];
            }
        }
        
        return dp;
    }
    
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> pal = getPalindromicSubstrings(s);
        
        vector<int> dp(n,1e9);
    
        for(int i=0; i<n; i++) {
            
            // for(int j=0; j<=i; i++) {
            
            for(int j=i; j>=0; j--) {
                if(pal[j][i]) {
                    if(j==0) dp[i] = min(dp[i], 1);
                    else dp[i] = min(dp[i], dp[j-1]+1);
                }
            }
        } 
        
        return dp[n-1]-1;
    }
};