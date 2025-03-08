// https://leetcode.com/problems/construct-k-palindrome-strings

class Solution {
public:
    bool canConstruct(string s, int k) {

        // edge case missed, formulating an over complicated logic to handle
        if (s.length() < k) {
            return false;
        }

        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }

        int evenFreq = 0;
        int oddFreq = 0;
        for (int i = 0; i < 26; i++) {
            evenFreq += freq[i] / 2;
            oddFreq += freq[i] % 2;
        }

        return oddFreq <= k;
    }
};