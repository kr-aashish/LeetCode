class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = n[0];
        for (int i = 1; i <= n.length(); i++) {
            maxDigit = max(maxDigit, n[i]);
        }
        return maxDigit - '0';
    }
};