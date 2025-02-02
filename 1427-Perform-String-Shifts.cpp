class Solution {
public:
    string stringShift(string string, vector<vector<int>>& shift) {
        int len = string.length();
        for (auto move : shift) {
            int direction = move[0];
            int amount = move[1] % len;
            if (direction == 0) {
                string = string.substr(amount) + string.substr(0, amount);
            } else {
                string = string.substr(len - amount) +
                         string.substr(0, len - amount);
            }
        }
        return string;
    }
};