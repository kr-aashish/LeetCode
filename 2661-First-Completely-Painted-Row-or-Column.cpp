// https://leetcode.com/problems/first-completely-painted-row-or-column

class Solution {
public:
    // Hash Table
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numberOfRows = mat.size();
        int numberOfColumns = mat.back().size();
        map<int, pair<int, int>> valuesInMatrix;
        map<int, int> rows;
        map<int, int> columns;

        for (int i = 0; i < numberOfRows; i++) {
            for (int j = 0; j < numberOfColumns; j++) {
                valuesInMatrix[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            auto coordinates = valuesInMatrix[arr[i]];
            int row = coordinates.first;
            int column = coordinates.second;

            rows[row]++;
            columns[column]++;
            if (rows[row] == numberOfColumns or 
                columns[column] == numberOfRows) {
                return i;
            }
        }

        return -1;
    }
};