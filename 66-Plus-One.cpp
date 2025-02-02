// https://leetcode.com/problems/plus-one/
// Scenarios to handle
// [2,7,9]
// [2,9,9]
// [9,9,9]
// digits.insert(digits.begin(), 1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;        
    }
};