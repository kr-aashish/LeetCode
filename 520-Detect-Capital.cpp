class Solution {
    pair<int, int> countLetters(string word) {
        int capital = 0, small = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' and word[i] <= 'Z')
                capital++;
            else 
                small++;
        }
        return {capital, small};
    }

public:
    bool detectCapitalUse(string word) {
        auto count = countLetters(word);
        int capital = count.first, small = count.second;

        if (word[0] >= 'A' and word[0] <= 'Z') {
            if (capital == word.length() or small == int(word.length()) - 1)
                return true;
        } else {
            if (small == word.length())
                return true;
        }

        return false;
    }
};