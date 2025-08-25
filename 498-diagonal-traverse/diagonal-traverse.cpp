class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat.back().size();

        vector<int> diagonalOrder;

        int row = 0;
        int col = 0;

        int dirn = 1;
        while (row >= 0 and row < rows and col >= 0 and col < cols) {
            diagonalOrder.push_back(mat[row][col]);

            int nextRow = row - dirn;
            int nextCol = col + dirn;

            if (nextRow >= 0 and nextRow < rows and
                nextCol >= 0 and nextCol < cols) {
                row = nextRow;
                col = nextCol;        
            } else {
                if (dirn > 0) {
                    if (row == 0) {
                        col++;
                    } else {
                        row++;
                    }
                } else {
                    if (col == 0) {
                        row++;
                    } else {
                        col++;
                    }
                }

                if (col >= cols) {
                    row++;
                    col--;
                }
                if (row >= rows) {
                    col++;
                    row--;
                }

                dirn = -dirn;
            }
        }

        return diagonalOrder;
    }
};