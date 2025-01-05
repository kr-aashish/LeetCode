class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size = s.length();
        vector<int> partialSum(size, 0);

        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction) {
                partialSum[start]++;
                if (end + 1 < size) {
                    partialSum[end + 1]--;
                }
            } else {
                partialSum[start]--;
                if (end + 1 < size) {
                    partialSum[end + 1]++;
                }
            }
        }

        string shiftedString;
        for (int i = 0; i < size; i++) {
            if (i) {
                partialSum[i] += partialSum[i - 1];
            }
        }
        for (int i = 0; i < size; i++) {
            int result = (s[i] - 'a') + partialSum[i];
            result = (result % 26 + 26) % 26;
            shiftedString += result + 'a';
        }
        return shiftedString;
    }
};