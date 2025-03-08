class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = n - 1; i > n - k; i--) {
            freq[nums[i]]++;
        }

        vector<int> ans;
        for (int i = n - k; i >= 0; i--) {
            freq[nums[i]]++;

            ans.push_back(freq.size());

            freq[nums[i + k - 1]]--;
            if (freq[nums[i + k - 1]] == 0) {
                freq.erase(nums[i + k - 1]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};