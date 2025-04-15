class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xorValue = 0;

        // XOR all numbers from 1 to n^2
        for (int i = 1; i <= n * n; i++) {
            xorValue ^= i;
        }
        // XOR all numbers in the grid
        for (auto& row : grid) {
            for (int num : row) {
                xorValue ^= num;
            }
        }
        // xorValue now equals (repeated XOR missing)

        // Isolate the rightmost set bit in xorValue
        int setBit = xorValue & (-xorValue);
        int x = 0, y = 0;

        // Partition numbers 1 to n^2 into two groups based on the set bit
        for (int i = 1; i <= n * n; i++) {
            if (i & setBit)
                x ^= i;
            else
                y ^= i;
        }
        // Partition grid numbers into two groups based on the set bit
        for (auto& row : grid) {
            for (int num : row) {
                if (num & setBit)
                    x ^= num;
                else
                    y ^= num;
            }
        }
        // Now, x and y are the two candidates but we don't know
        // which one is the repeated number and which is missing.

        // Determine which candidate is repeated in the grid
        int count = 0;
        for (auto& row : grid) {
            for (int num : row) {
                if (num == x)
                    count++;
            }
        }
        if (count == 2)
            return {x, y}; // x is repeated, y is missing
        else
            return {y, x}; // y is repeated, x is missing
    }
};