class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        vector<string> mappings(10);
        vector<bool> done(26, false);
        while (true) {
            int count = 1;
            while (count < 10) {
                int character = -1;
                int maxFreq = -1;
                for (int i = 0; i < 26; i++) {
                    if (done[i]) {
                        continue;
                    }

                    if (freq[i] > maxFreq) {
                        maxFreq = freq[i];
                        character = i;
                    }
                }
                if (character != -1) {
                    mappings[count].push_back('a' + character);
                    done[character] = true;
                }
                count++;
            }

            bool isDone = true;
            for (auto status : done) {
                if (!status) {
                    isDone = false;
                    break;
                }
            }
            if (isDone) {
                break;
            }
        }

        int keypresses = 0;
        for (auto character : s) {
            for (int i = 1; i < 10; i++) {
                auto mapping = mappings[i];
                int keypress = 0;
                for (int j = 0; j < mapping.length(); j++) {
                    if (mapping[j] == character) {
                        keypress += j + 1;
                        break;
                    }
                }
                if (keypress) {
                    keypresses += keypress;
                    break;
                }
            }
        }

        return keypresses;
    }
};