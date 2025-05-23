class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (index.count(remaining)) {
                return {index[remaining], i};
            }
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};
