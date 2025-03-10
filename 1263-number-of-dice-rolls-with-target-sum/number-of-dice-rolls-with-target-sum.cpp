class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int waysToTarget(vector<vector<int>>& memo, int diceIndex, int n, int currSum, int target, int k) {
        if (diceIndex == n) {
            return currSum == target;
        }

        if (memo[diceIndex][currSum] != -1) {
            return memo[diceIndex][currSum];
        }
		
        int ways = 0;
        for (int i = 1; i <= min(k, target - currSum); i++) {
            ways = (ways + waysToTarget(memo, diceIndex + 1, n, currSum + i, target, k)) % MOD;
        }
        return memo[diceIndex][currSum] = ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return waysToTarget(memo, 0, n, 0, target, k);
    }
};