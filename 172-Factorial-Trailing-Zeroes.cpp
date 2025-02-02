class Solution {
public:
    int trailingZeroes(int n) {
        int countZeros = 0;

        int divisionFactor = 5;
        while (n) {
            countZeros += n/divisionFactor;
            n /= divisionFactor;
        }

        return countZeros;
    }
};