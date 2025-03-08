// https://leetcode.com/problems/make-the-prefix-sum-non-negative
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long long prefixSum = 0;
        int operations = 0;

        for (auto num : nums) {
            if (num < 0) {
                pq.push(num);
            }
            
            prefixSum += num;

            if (prefixSum < 0) {
                prefixSum -= pq.top();
                pq.pop();
                operations++;
            }
        }

        return operations;
    }
};