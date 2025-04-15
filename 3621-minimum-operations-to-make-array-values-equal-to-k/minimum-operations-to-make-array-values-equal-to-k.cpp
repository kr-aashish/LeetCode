// Approach: Freq map, rev iteration -> rev not required

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (auto num : nums) {
            freqMap[num]++;

            if (num < k) {
                return -1;
            }
        }

        int count = 0;
        for (auto keyValue : freqMap) {
            if (keyValue.first > k) {
                count++;
            }
        }

        return count;
    }
};