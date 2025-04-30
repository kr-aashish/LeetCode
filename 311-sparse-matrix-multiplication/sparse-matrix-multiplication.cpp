class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1.back().size();
        int n = mat2.back().size();

        vector<vector<int>> result(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                for (int p = 0; p < n; p++) {
                    result[i][p] += mat1[i][j] * mat2[j][p];
                }
            }
        }

        return result;
    }
};