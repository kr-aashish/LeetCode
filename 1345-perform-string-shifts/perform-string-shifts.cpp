class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string result = s;
        int len = s.length();
        for (auto value : shift) {
            int direction = value[0];
            int amount = value[1];
            amount %= len;
            
            if (direction == 0) {
                result = result.substr(amount) + result.substr(0, amount);
            } else {
                result = result.substr(len - amount) + result.substr(0, len - amount);
            }
        }

        return result;
    }
};