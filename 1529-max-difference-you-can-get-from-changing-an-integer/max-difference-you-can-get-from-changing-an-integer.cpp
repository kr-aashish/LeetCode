class Solution {
public:
    int maxDiff(int num) {
        string numStr = to_string(num);
        int len = numStr.size();
        string changeX = numStr;

        int idxOne = 0;
        while (idxOne < len and numStr[idxOne] <= '1') {
            idxOne++;
        }
        char characterToChangeOne = numStr[idxOne];
        char minChar = idxOne == 0 ? '1' : '0';
        string minStr = numStr;
        for (auto &character : minStr) {
            if (character == characterToChangeOne) {
                character = minChar;
            }
        }

        int idxTwo = 0;        
        while (idxTwo < len and numStr[idxTwo] == '9') {
            idxTwo++;
        }
        char characterToChangeTwo = numStr[idxTwo];
        string maxStr = numStr;
        for (auto &character : maxStr) {
            if (character == characterToChangeTwo) {
                character = '9';
            }
        }

        cout << maxStr << " " << minStr << endl;
        return stoi(maxStr) - stoi(minStr);
    }
};