// Approach: Map and iterate

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        int index = 0;
        int operations = 0;
        int numsCount = nums.size();
        while (index < numsCount) {
            int noDuplicates = true;
            for (auto keyValue : freq) {
                if (keyValue.second > 1) {
                    noDuplicates = false;
                }
            }
            if (noDuplicates) {
                break;
            }

            if (freq[nums[index]] > 1) {
                freq[nums[index]]--;
            }
            if (index + 1 < numsCount and freq[nums[index + 1]] > 1) {
                freq[nums[index + 1]]--;
            }
            if (index + 2 < numsCount and freq[nums[index + 2]] > 1) {
                freq[nums[index + 2]]--;
            }

            operations++;
            index += 3;
        }

        return operations;
    }
};