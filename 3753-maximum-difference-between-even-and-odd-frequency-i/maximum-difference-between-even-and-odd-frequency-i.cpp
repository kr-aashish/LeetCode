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
                cout << string(1, 'a' + i) << " " << freq[i] << endl;
                maxFreqOdd = freq[i];
            }
            if (freq[i] != 0 and freq[i] % 2 == 0 and freq[i] < minFreqEven) {
                cout << string(1, 'a' + i) << " " << freq[i] << endl;
                minFreqEven = freq[i];
            }
        }

        cout << maxFreqOdd << " " << minFreqEven << endl;
        return maxFreqOdd - minFreqEven;
    }
};
