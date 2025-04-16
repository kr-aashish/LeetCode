class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> digitsPlusOne;  
        int sz = digits.size();

        int carry = 1;
        for (int i = sz - 1; i >= 0; i--) {
            int value = carry + digits[i];

            int updatedDigit;
            if (value < 10) {
                updatedDigit = value;
                carry = 0;
            } else {
                updatedDigit = value % 10;
                carry = value / 10;
            }

            digitsPlusOne.push_back(updatedDigit);
        }
        if (carry) {
            digitsPlusOne.push_back(carry);
        }

        reverse(digitsPlusOne.begin(), digitsPlusOne.end());
        return digitsPlusOne;
    }
};