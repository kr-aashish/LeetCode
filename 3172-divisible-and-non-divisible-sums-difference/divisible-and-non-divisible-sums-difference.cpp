class Solution {
public:
    // m, 2m, 3m, 4m...
    int differenceOfSums(int n, int m) {
        int count = n / m;
        int sum = (count * (count + 1) / 2) * m;
        int totSum = n * (n + 1) / 2;
        int num1 = totSum - sum;
        int num2 = sum;
        return num1 - num2;
    }
};