class Solution {
public:
    int smallestNumber(int n) {
        int numberWithAllSetBits = 1;
        for (int i = 1; i < 31; i++) {
            if (numberWithAllSetBits >= n) {
                break;
            }
            numberWithAllSetBits |= (1 << i); 
        }
        return numberWithAllSetBits;
    }
};