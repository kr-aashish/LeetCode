// Unique solution
class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        stack<char> digits;

        for (int i = 0; i <= pattern.size(); i++) {
            digits.push(i + 1);

            if (pattern[i] == 'I' or i == pattern.size()) {
                while (!digits.empty()) {
                    result += ('0' + digits.top());
                    digits.pop();
                }
            }
        }

        return result;
    }
};