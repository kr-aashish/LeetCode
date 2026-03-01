class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int pointer = 0;
            while (pointer < answer.size() && pointer < strs[i].size()) {
                if (answer[pointer] == strs[i][pointer]) {
                    pointer++;
                } else {
                    break;
                }
            }
            answer = answer.substr(0, pointer);
        }

        return answer;
    }
};