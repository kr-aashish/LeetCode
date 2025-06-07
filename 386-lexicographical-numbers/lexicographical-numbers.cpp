class Solution {
    void generateLexicalOrder(string str, vector<int> &result, int n) {
        if (str.length() > to_string(n).length()) {
            return;
        }

        if (stoi(str) <= n) {
            result.push_back(stoi(str));
        }

        for (char character = '0'; character <= '9'; character++) {
            generateLexicalOrder(str + character, result, n);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        string currentStr = "";
        for (char character = '1'; character <= '9'; character++) {
            generateLexicalOrder(currentStr + character, result, n);
        }
        return result;
    }
};