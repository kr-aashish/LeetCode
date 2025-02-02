class Solution {
    vector<int> getSieve(int N) {
        vector<int> sieve(N + 2, 1);
        sieve[0] = sieve[1] = 0;
        for (int i = 2; 1LL * i * i <= N; i++) {
            if (sieve[i]) {
                for (int j = 2 * i; j <= N; j += i) 
                    sieve[j] = 0;
            }
        }
        return sieve;
    }

public:
    int countPrimes(int n) {
        vector<int> sieve = getSieve(n);
        
        int primeCounter = 0;
        for (int i = 1; i < n; i++) 
            primeCounter += sieve[i];

        return primeCounter;
    }
};