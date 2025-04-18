class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string runLengthEncoding = countAndSay(n - 1);
        int index = 0;
        int len = runLengthEncoding.length();
        string result = "";
        while (index < len) {
            int count = 1;
            while (index + 1 < len and runLengthEncoding[index] == runLengthEncoding[index + 1]) {
                index++;
                count++;
            }
            result += ('0' + count);
            result += runLengthEncoding[index];
            index++;
        }
        return result;
    }
};