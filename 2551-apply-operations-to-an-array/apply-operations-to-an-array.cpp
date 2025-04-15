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

        vector<int> result;
        for (auto num : nums) {
            if (num) {
                result.push_back(num);
            }
        }
        while (result.size() < sz) {
            result.push_back(0);
        }

        return result;
    }
};