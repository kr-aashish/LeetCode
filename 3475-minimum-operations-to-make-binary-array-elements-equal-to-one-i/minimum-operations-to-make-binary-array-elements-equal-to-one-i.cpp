class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        vector<int> flips(sz, 0);

        int operations = 0;
        for (int i = 0; i < sz; i++) {
            if (i) {
                flips[i] += flips[i - 1];
            }

            int currentValue = (nums[i] + flips[i]) % 2;

            if (i + 2 > sz - 1 and currentValue == 0) {
                operations = -1;
                break;
            }

            if (currentValue == 0) {
                flips[i] += 1;
                if (i + 3 < sz) {
                    flips[i + 3] -= 1;
                }
                operations++;
            }
        }

        return operations;
    }
};