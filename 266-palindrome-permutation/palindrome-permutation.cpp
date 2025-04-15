class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }

        int countOfOddCharacters = 0;
        for (int i = 0; i < 26; i++) {
            countOfOddCharacters += (freq[i] % 2);
        }

        return countOfOddCharacters <= 1;
    }
};