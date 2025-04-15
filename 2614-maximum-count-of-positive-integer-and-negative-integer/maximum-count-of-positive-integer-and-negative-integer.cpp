class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positiveCount = 0;
        int negativeCount = 0;
        
        for (auto num : nums) {
            positiveCount += num > 0;
            negativeCount += num < 0;
        }

        int count = max(positiveCount, negativeCount);
        return count;
    }
};