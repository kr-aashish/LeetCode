class Solution {
    int getSumOfDigits(int num) {
        int sumOfDigits = 0;
        while (num) {
            sumOfDigits += (num % 10);
            num /= 10;
        }
        return sumOfDigits;
    }

public:
    int maximumSum(vector<int>& nums) {
        int maximumSum = -1;
        vector<int> sum(82, 0);
        for (auto num : nums) {
            int sumOfDigits = getSumOfDigits(num);
            if (sum[sumOfDigits]) {
                maximumSum = max(maximumSum, num + sum[sumOfDigits]);
            }
            sum[sumOfDigits] = max(sum[sumOfDigits], num);
        }
        return maximumSum;
    }
};