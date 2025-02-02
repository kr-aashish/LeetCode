class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int numsSize = nums.size();
    	vector<int> longestIncreasingSubsequence;
    	longestIncreasingSubsequence.push_back(nums[0]);
    	
    	for (int i = 0; i < numsSize; i++) {
    		if (nums[i] > longestIncreasingSubsequence.back()) {
    			longestIncreasingSubsequence.push_back(nums[i]);
    		} else {
    			auto currIteratator = lower_bound(longestIncreasingSubsequence.begin(), 
    				longestIncreasingSubsequence.end(), nums[i]);
    			*currIteratator = nums[i];
    		}
    	}
    	
    	return longestIncreasingSubsequence.size();
    }
};