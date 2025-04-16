class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int sz = arr.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 2));
        unordered_map<int, int> index;
        for (int i = 0; i < sz; i++) {
            index[arr[i]] = i;
        }

        int longestLen = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                int kValue = arr[i] - arr[j];

                if (index.count(kValue) and index[kValue] < j) {
                    int k = index[kValue];
                    dp[j][i] = max(dp[j][i], dp[k][j] + 1);
                    longestLen = max(longestLen, dp[j][i]);
                }
            }
        }

        return longestLen >= 3 ? longestLen : 0;
    }
};