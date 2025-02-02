class Solution {
    int N,M;
    vector<vector<char>> a;
    int dp[303][303];
    
    int recur(int i, int j) {
        if(i<0 or j<0) return 0;
        
        if(i==0 and j==0) return a[i][j]-'0';
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        if(a[i][j]-'0') ans = min({recur(i-1, j-1), recur(i-1, j), recur(i, j-1)})+1;
        
        return dp[i][j] = ans;
    }
    
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        N = matrix.size(); M = matrix.back().size(); a = matrix;
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for(int i=0; i<N; i++) for(int j=0; j<M; j++) ans = max(ans, recur(i, j));
        
        return ans*ans;
    }
};