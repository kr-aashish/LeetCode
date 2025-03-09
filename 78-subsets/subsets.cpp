class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numberOfSubsets = (1 << (nums.size()));

        vector<vector<int>> subsets;
        for (int mask = 0; mask < numberOfSubsets; mask++) {
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++) {
                if (mask & (1 << j))
                    subset.push_back(nums[j]);
            }
            subsets.push_back(subset);
        }

        return subsets;
    }
};