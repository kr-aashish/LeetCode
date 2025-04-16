class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }

        vector<int> parts;
        int partSize = 0;
        vector<int> currentFreq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            currentFreq[s[i] - 'a']++;
            partSize++;

            bool currentPartComplete = true;
            for (int j = 0; j < 26; j++) {
                if (currentFreq[j]) {
                    if (currentFreq[j] != freq[j]) {
                        currentPartComplete = false;
                    }
                }
            }

            if (currentPartComplete) {
                parts.push_back(partSize);
                partSize = 0;
            }
        }

        if (partSize) {
            parts.push_back(partSize);
        }

        return parts;
    }
};