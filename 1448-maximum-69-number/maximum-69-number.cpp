// Use numeric operations to do the digit flip in O(1)

class Solution {
    int binaryExponentiation (int base, int pow) {
        int result = 1;

        while (pow) {
            if (pow % 2) {
                result = result * base;
            }

            base *= base;
            pow /= 2;
        }

        return result;
    }
    
public:
    int maximum69Number (int num) {
        int len = to_string(num).length();

        int output = num;
        for (int i = len - 1; i >= 0; i--) {
            int digit = (output / binaryExponentiation(10, i)) % 10;

            if (digit == 6) {
                output -= 6 * binaryExponentiation(10, i);
                output += 9 * binaryExponentiation(10, i);
                break;
            }
        }

        return output;
    }
};