class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int sz = nums.size();

        int maxEle = nums[0];
        for (auto num : nums) {
            maxEle = max(maxEle, num);
        }

        int head = -1;
        int tail = 0;
        long long count = 0;
        int freq = 0;
        while (tail < sz) {
            while (head + 1 < sz and freq < k) {
                head++;
                freq += nums[head] == maxEle;
            }

            if (freq == k) {
                count += sz - 1 - head + 1;
            }

            if (head < tail) {
                tail++;
                head = tail - 1;
            } else {
                freq -= nums[tail] == maxEle;
                tail++;
            }
        }

        return count;
    }
};