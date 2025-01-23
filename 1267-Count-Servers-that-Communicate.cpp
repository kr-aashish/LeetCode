// https://leetcode.com/problems/count-servers-that-communicate
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m, 0);
        vector<int> columns(n, 0);

        // Step 1: Count servers in each row and column
        for (int row = 0; row < m; row++) {
            for (int column = 0; column < n; column++) {
                if (grid[row][column] == 1) {
                    rows[row]++;
                    columns[column]++;
                }
            }
        }

        // Step 2: Count servers that can communicate
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int column = 0; column < n; column++) {
                if (grid[row][column] == 1 && (rows[row] > 1 || columns[column] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};