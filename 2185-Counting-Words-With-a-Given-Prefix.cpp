class Solution {
    bool isPrefix(string word, string prefix) {
        if (word.length() < prefix.length()) {
            return false;
        }

        for (int i = 0; i < prefix.length(); i++) {
            if (word[i] != prefix[i]) {
                return false;
            }
        }

        return true;
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto word : words) {
            count += isPrefix(word, pref);
        }
        return count;
    }
};