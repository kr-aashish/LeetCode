class Solution {
    const int mod = 1e9 + 7;

    long long binExp(long long base, long long power) {
        long long value = 1;
        base %= mod;
        power %= (mod - 1);

        while (power) {
            if (power % 2) {
                value *= base;
                value %= mod;
            }

            base *= base;
            base %= mod;

            power /= 2;
        }

        return value;
    }

public:
    int countGoodNumbers(long long n) {
        long long evenPlaces = n / 2;
        long long oddPlaces = n - evenPlaces;

        long long count = binExp(5, oddPlaces) * binExp(4, evenPlaces) % mod;

        return count;
    }
};