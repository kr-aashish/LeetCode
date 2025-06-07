// Greedy, shifting stars
class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> freq(26);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                freq[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (freq[j].size()) {
                        int idx = freq[j].top();
                        freq[j].pop();
                        s[idx] = '*';
                        break;
                    }
                }
            }
        }
        string clearStars;
        for (auto character : s) {
            if (character != '*') {
                clearStars += character;   
            }
        }
        return clearStars;
    }
};