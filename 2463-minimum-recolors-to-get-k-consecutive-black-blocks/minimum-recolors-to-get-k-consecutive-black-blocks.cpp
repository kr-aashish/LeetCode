class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int len = blocks.length();
        vector<int> prefixSum(len, 0);

        for (int i = 0; i < len; i++) {
            prefixSum[i] = blocks[i] == 'B';
            
            if (i) {
                prefixSum[i] += prefixSum[i - 1];
            }
        }

        int minOperations = len;
        for (int i = k - 1; i < len; i++) {
            int value = prefixSum[i];
            if (i - k >= 0) {
                value -= prefixSum[i - k];
            }
            minOperations = min(minOperations, k - value);
        }
        return minOperations;
    }
};