class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sz = nums.size();

        int tail = 0;
        int head = -1;

        int zeroCount = 0;
        int maxLen = 0;
        while (tail < sz) {
            while (head + 1 < sz and 
                (zeroCount == 0 or (zeroCount == 1 and nums[head + 1] != 0))) {
                head++;
                zeroCount += nums[head] == 0;
            }

            maxLen = max(maxLen, head - tail + 1 - zeroCount);

            if (head < tail) {
                tail++;
                head = tail - 1;
            } else {
                zeroCount -= nums[tail] == 0;
                tail++;
            }
        }

        int allOne = 1;
        for (auto num : nums) {
            allOne &= num;
        }

        if (allOne) {
            maxLen--;
        }

        return maxLen;
    }
};