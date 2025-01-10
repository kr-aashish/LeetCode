class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        for (auto word : words2) {
            vector<int> currFreq(26, 0);
            for (auto character : word) {
                currFreq[character - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = max(freq[i], currFreq[i]);
            }
        }

        vector<string> universalStrings;
        for (auto word : words1) {
            bool isUniversalString = true;
            vector<int> currFreq(26, 0);
            for (auto character : word) {
                currFreq[character - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (currFreq[i] < freq[i]) {
                    isUniversalString = false;
                }
            }
            if (isUniversalString) {
                universalStrings.push_back(word);
            }
        }

        return universalStrings;
    }
};