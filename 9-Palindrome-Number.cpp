class Solution {
public:
    bool isPalindrome(int x) {
        string valueAsString = to_string(x);
        string reversedValueAsString = valueAsString;
        reverse(reversedValueAsString.begin(), reversedValueAsString.end());
        return valueAsString == reversedValueAsString;
    }
};