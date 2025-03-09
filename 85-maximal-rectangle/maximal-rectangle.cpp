class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size(), m = a.back().size();
        int dp[n][m];
        
        // for(int i=0; i<n; i++) dp[i][0] = a[i][0]-'0';
        // for(int j=0; j<m; j++) dp[0][j] = a[0][j]-'0';
        
        int ans = 0; 
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                dp[i][j] = a[i][j] - '0';
                if(j and dp[i][j]) dp[i][j] = dp[i][j-1] + 1;
                
                int width = dp[i][j];
                for(int x=i; x>=0; x--) {
                    width = min(width, dp[x][j]);
                    ans = max(ans, width*(i-x+1));
                }
            }
        }
        return ans;
    }
};