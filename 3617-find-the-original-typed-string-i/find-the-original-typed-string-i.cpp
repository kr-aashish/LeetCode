// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
};