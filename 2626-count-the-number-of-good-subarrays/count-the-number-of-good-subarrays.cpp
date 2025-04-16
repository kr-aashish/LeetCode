class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int N = nums.size();

        int tail = 0;
        int head = -1;
        long long count = 0;
        long long goodSubarrays = 0;

        while (tail < N) {
            while (head + 1 < N and count < k) {
                head++;
                count += freq[nums[head]];
                freq[nums[head]]++;
            }

            if (count >= k) {
                goodSubarrays += (N - head);
            }

            if (head < tail) {
                tail++;
                head = tail - 1;
            } else {
                count -= (freq[nums[tail]] - 1);
                freq[nums[tail]]--;
                tail++;
            }
        }

        return goodSubarrays;
    }
};