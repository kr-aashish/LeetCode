class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> prefixCommonArray(len, 0);
        vector<int> freqOne(len + 1, 0);
        vector<int> freqTwo(len + 1, 0);

        for (int i = 0; i < len; i++) {
            freqOne[A[i]]++;
            freqTwo[B[i]]++;

            for (int val = 1; val <= len; val++) {
                prefixCommonArray[i] += freqOne[val] and freqTwo[val];
            }
        }

        return prefixCommonArray;
    }
};