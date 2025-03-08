const vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

class Solution {
    bool isVowel(char character) {
        for (auto vowel : vowels) {
            if (character == vowel) {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int count = words.size();
        vector<int> prefixSum(count);
        for (int i = 0; i < count; i++) {
            string word = words[i];
            prefixSum[i] = isVowel(word[0]) and isVowel(word.back());
            if (i) {
                prefixSum[i] += prefixSum[i - 1];
            }
        }

        vector<int> result;
        for (auto query : queries) {
            int l = query[0];
            int r = query[1];

            result.push_back(prefixSum[r] - (l ? prefixSum[l - 1] : 0));
        }

        return result;
    }
};