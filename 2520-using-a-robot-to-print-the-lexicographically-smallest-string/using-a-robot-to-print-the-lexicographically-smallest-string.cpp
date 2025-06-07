// Process can be simulated by a stack
// Lexiographically smallest sequence of popping
class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26);
        for (auto character : s) {
            freq[character - 'a']++;
        }

        stack<char> stack;
        string result;
        char minChar = 'a';
        for (auto character : s) {
            stack.push(character);
            freq[character - 'a']--;

            while (minChar != 'z' and freq[minChar - 'a'] == 0) {
                minChar++;
            }

            while (!stack.empty() and stack.top() <= minChar) {
                result += stack.top();
                stack.pop();
            }
        }

        return result;
    }
};