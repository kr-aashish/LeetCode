class Solution {
    //dp[i][j] - min operation required to make 0,1,...,i of word1 to 0,1,2...,i of word2
    //if word1[i] == word2[j] -> dp[i][j] = dp[i - 1][j - 1]
    //else 3 cases!

    int getMinOperations(int i, int j, int lenWord1, int lenWord2, 
        vector<vector<int>> &memorise, string word1, string word2) {
        if (i > lenWord1 or j > lenWord2)
            return 1e9;

        if (i == lenWord1 and j == lenWord2) 
            return 0;

        if (memorise[i][j] != -1)
            return memorise[i][j];

        int numberOfOperations = 0;
        if (word1[i] == word2[j]) {
            numberOfOperations = getMinOperations(i + 1, j + 1, lenWord1, lenWord2, 
                memorise, word1, word2);
        } else {
            numberOfOperations = min({getMinOperations(i, j + 1, lenWord1, lenWord2, 
                memorise, word1, word2), getMinOperations(i + 1, j, lenWord1, lenWord2, 
                memorise, word1, word2), getMinOperations(i + 1, j + 1, lenWord1, lenWord2, 
                memorise, word1, word2)}) + 1;
        }

        return memorise[i][j] = numberOfOperations;
    }

public:
    int minDistance(string word1, string word2) {
        int lenWord1 = word1.length(), lenWord2 = word2.length();
        vector<vector<int>> memorise(lenWord1 + 1, vector<int>(lenWord2 + 1, -1));
        return getMinOperations(0, 0, lenWord1, lenWord2, memorise, word1, word2);
    }
};