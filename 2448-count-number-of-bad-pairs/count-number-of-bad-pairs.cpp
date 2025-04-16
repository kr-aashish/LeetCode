class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> values;

        long long count = 0;
        for (int i = 0; i < sz; i++) {
            count += values[nums[i] - i];
            values[nums[i] - i]++;
        }

        long long total = 1LL * sz * (sz - 1);
        total /= 2;

        return total - count;
    }
};