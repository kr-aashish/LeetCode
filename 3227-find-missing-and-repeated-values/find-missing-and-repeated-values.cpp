class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xorValue = 0;
        int n = grid.size();

        for (int i = 1; i <= n * n; i++) {
            xorValue ^= i;
        }

        for (auto row : grid) {
            for (auto num : row) {
                xorValue ^= num;
            }
        }

        int lastSetBit = (xorValue & (~(xorValue - 1)));
        int valueOne = 0;
        int valueTwo = 0;
        for (int i = 1; i <= n * n; i++) {
            if (lastSetBit & i) {
                valueOne ^= i;
            } else {
                valueTwo ^= i;
            }
        }
        for (auto row : grid) {
            for (auto num : row) {
                if (lastSetBit & num) {
                    valueOne ^= num;
                } else {
                    valueTwo ^= num;
                }
            }
        }

        int countOne = 0;
        int countTwo = 0;
        for (auto row : grid) {
            for (auto num : row) {
                countOne += (valueOne == num);
                countTwo += (valueTwo == num);
            }
        }

        return countOne == 2 ? vector<int>{valueOne, valueTwo} : vector<int>{valueTwo, valueOne};
    }
};