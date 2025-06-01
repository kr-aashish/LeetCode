class Solution {
    int calculatePower(int value, int power) {
        return power % 2 == 0 ? 1 : -1;
    }

    long long nCr(int n, int r) {
        // n less than r case
        if (n < r) {
            return 0;
        }

        // Negative case [r can max go till 2]
        if (r == 2) {
            if (n < 2) {
                return 0;
            } else {
                return 1LL * n * (n - 1) / 2;
            }
        }

        long long value = 1;
        for (int i = 1; i <= n; i++) {
            value *= i;
        }
        for (int i = 1; i <= (n - r); i++) {
            value /= i;
        }
        for (int i = 1; i <= r; i++) {
            value /= i;
        }
        return value;
    }

public:
    long long distributeCandies(int n, int limit) {
        long long numberOfWays = 0;
        for (int i = 0; i <= 3; i++) { // loop not < 3
            numberOfWays += nCr(n - (limit + 1) * i + 3 - 1, 3 - 1) * nCr(3, i) * calculatePower(-1, i);
        }
        return numberOfWays;
    }
};