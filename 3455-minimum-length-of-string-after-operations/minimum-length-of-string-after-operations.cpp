class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }

        int minLen = 0;
        for (int i = 0; i < 26; i++) {
            if (!freq[i]) {
                continue;
            }

            if (freq[i] % 2) {
                minLen++;
            } else {
                minLen += 2;
            }
        }

        return minLen;
    }
};