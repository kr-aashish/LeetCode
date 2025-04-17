class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<long long> prefixSum(sz, 0);
        multiset<pair<long long, int>> sums;
        int maxLen = 0;
        for (int i = 0; i < sz; i++) {
            prefixSum[i] = nums[i];
            if (i) {
                prefixSum[i] += prefixSum[i - 1];
            }

            auto prev = sums.lower_bound({prefixSum[i] - k, -1});
            if (prev != sums.end() and prefixSum[i] - k == (*prev).first) {
                int prevIndex = (*prev).second;
                maxLen = max(maxLen, i - prevIndex);
            }
            if (prefixSum[i] == k) {
                maxLen = max(maxLen, i + 1);
            }

            auto it = sums.lower_bound({prefixSum[i], -1});
            if (it == sums.end() or (*it).first != prefixSum[i]) {
                sums.insert({prefixSum[i], i});   
            }
        }

        return maxLen;
    }
};