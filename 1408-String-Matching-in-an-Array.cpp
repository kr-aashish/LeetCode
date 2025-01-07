class Solution {
    bool isSubstringOf(string main, string child) {
        bool isSubstring = false;
        for (int i = 0; i < main.length(); i++) {
            if (main[i] == child[0]) {
                isSubstring = isSubstring or (main.substr(i, child.length()) == child);
            }
        }
        return isSubstring;
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> substringWords;
        for (auto main : words) {
            for (auto child : words) {
                if (main != child) {
                    if (isSubstringOf(main, child)) {
                        substringWords.insert(child);
                    }
                }
            }
        }
        vector<string> uniqueWords;
        for (auto word : substringWords) {
            uniqueWords.push_back(word);
        }
        return uniqueWords;
    }
};