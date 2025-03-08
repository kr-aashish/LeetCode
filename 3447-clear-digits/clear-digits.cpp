class Solution {
public:
    string clearDigits(string s) {
        stack<char> nearestCharacters;
        for (auto character : s) {
            if (character >= '0' and character <= '9') {
                if (!nearestCharacters.empty()) {
                    nearestCharacters.pop();
                }
                continue;
            } else {
                nearestCharacters.push(character);
            }
        }
        string result = "";
        while (!nearestCharacters.empty()) {
            result += nearestCharacters.top();
            nearestCharacters.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};