class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs.back().length();
        int count = 0;

        for (int i = 0; i < cols; i++) {
            for (int j = 1; j < rows; j++) {
                if (strs[j][i] < strs[j - 1][i]) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};