// Missed the edge case, that's the most basic case too
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }

        int len = word.length();
        string result;
        for (int i = 0; i < len; i++) {
            result = max(result, word.substr(i, min(len - i, len - numFriends + 1)));
        }
        return result;
    }
};