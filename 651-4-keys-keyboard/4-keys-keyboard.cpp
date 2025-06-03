// diff will not be (i - k - 3) or (i - k - 2)
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + 1;

            // diff will not be (i - k - 3) or (i - k - 2)
            for (int k = 0; k + 3 <= i; k++) {
                dp[i] = max(dp[i], dp[k] * (i - k - 1));
            }
        }

        return dp[n - 1];
    }
};