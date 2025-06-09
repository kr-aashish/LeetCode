class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (auto character : s) {
            freq[character - 'a']++;
        }
        int maxFreqOdd = 0;
        int minFreqEven = s.length();
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 and freq[i] > maxFreqOdd) {
                maxFreqOdd = freq[i];
            }
            if (freq[i] != 0 and freq[i] % 2 == 0 and freq[i] < minFreqEven) {
                minFreqEven = freq[i];
            }
        }

        return maxFreqOdd - minFreqEven;
    }
};
