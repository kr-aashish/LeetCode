// Approach: Iterate

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int value = low; value <= high; value++) {
            string strValue = to_string(value);
            int lenStr = strValue.length();
            if (lenStr % 2) {
                continue;
            }
            int sumOfFirstNDigits = 0;
            int sumOfLastNDigits = 0;
            for (int i = 0; i < strValue.length(); i++) {
                int digit = strValue[i] - '0';
                if (i >= lenStr / 2) {
                    sumOfLastNDigits += digit;
                } else {
                    sumOfFirstNDigits += digit;
                }
            }
            count += (sumOfFirstNDigits == sumOfLastNDigits);
        }
        return count;
    }
};