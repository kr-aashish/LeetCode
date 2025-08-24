class Solution {
public:
    int jump(vector<int>& nums) {
        int count = nums.size();
        vector<int> jumps(count, 2 * count);
        jumps[0] = 0;
        for (int i = 0; i < count; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                int nextIdx = min(i + j, count - 1);
                jumps[nextIdx] = min(jumps[nextIdx], jumps[i] + 1);
            }
        }

        return jumps[count - 1];
    }
};