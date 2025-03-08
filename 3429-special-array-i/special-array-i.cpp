class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < int(nums.size()) - 1; i++) {
            int parityOfAdjacentSum = (nums[i] + nums[i + 1]) % 2;
            if (parityOfAdjacentSum == 0) {
                return false;
            }
        }
        return true;
    }
};