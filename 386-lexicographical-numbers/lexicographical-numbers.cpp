// Global way to append char to generate string
class Solution {
    void generateLexicalOrder(string str, vector<int> &result, int n) {
        if (stoi(str) > n) {
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
        string currentStr = ""; // must declare "", else array out of bound RTE
        for (char character = '1'; character <= '9'; character++) {
            generateLexicalOrder(currentStr + character, result, n);
        }
        return result;
    }
};