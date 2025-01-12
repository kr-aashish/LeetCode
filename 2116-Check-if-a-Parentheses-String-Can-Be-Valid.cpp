// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int N = s.length();

        if (N % 2) {
            return false;
        }

        int open = 0;
        for (int i = 0; i < N; i++) {
            open += s[i] == '(' or locked[i] == '0';
            open -= s[i] == ')' and locked[i] == '1';
            if (open < 0) {
                return false;
            }
        }

        int close = 0;
        for (int i = N - 1; i >= 0; i--) {
            close += s[i] == ')' or locked[i] == '0';
            close -= s[i] == '(' and locked[i] == '1';
            if (close < 0) {
                return false;
            }
        }

        return true;
    }
};