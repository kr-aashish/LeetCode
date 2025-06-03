// Shifting to end without extra space
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int index = 0;
        int nonZeroIndex = 0;
        while (index < sz) {
            if (nums[index] != 0) {
                nums[nonZeroIndex] = nums[index];
                nonZeroIndex++;
            }
            index++;
        }
        while (nonZeroIndex < sz) {
            nums[nonZeroIndex] = 0;
            nonZeroIndex++;
        }

        return nums;
    }
};