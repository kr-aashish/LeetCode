class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[2][amount+1];
        memset(dp, 0, sizeof(dp));
        
        // for(int i=0; i<=n; i++) dp[i][0] = 0;
        dp[0][0] = 0;
        for(int i=1; i<=amount; i++) dp[0][i] = 1e9;
        
        for(int i=1; i<=n; i++) {
            for(int w=0; w<=amount; w++) {
                dp[i&1][w] = dp[(i-1)&1][w];
                if(w>=coins[i-1]) dp[i&1][w] = min(dp[i&1][w], dp[i&1][w-coins[i-1]]+1);
            }
        }
        
        int ans = dp[n&1][amount];
        if(ans==1e9) ans = -1;
        
        return ans;
    }
};