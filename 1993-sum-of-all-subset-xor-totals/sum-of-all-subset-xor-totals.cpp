// Unique Solution
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orValue = 0;
        for (auto num : nums) {
            orValue |= num;
        }
        int sz = nums.size();
        return (1 << (sz - 1)) * orValue;
    }
};