class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, vector<string>> words;
        string word; int count = 0;
        for (auto character : s) {
            if (character == ' ') {
                words[pattern[count]].push_back(word);
                count++;
                word.clear();
            } else {
                word += character;
            }
        }
        words[pattern[count]].push_back(word);

        if (count + 1 != pattern.length())
            return false;

        unordered_map<string, string> patternForWords;
        for(auto word : words) {
            vector<string> wordVector = word.second;
            for (auto Word : wordVector)
                patternForWords[Word] += word.first;

            string firstWord = wordVector[0];
            for (int i = 1; i < wordVector.size(); i++) {
                if (wordVector[i] != firstWord)
                    return false;
            }
        }

        for (auto word : patternForWords) {
            cout << word.first << " " << word.second << endl;

            char firstChar = word.second[0];
            for (int i = 1; i < word.second.size(); i++) {
                if (word.second[i] != firstChar)
                    return false;
            }
        }

        return true;
    }
};