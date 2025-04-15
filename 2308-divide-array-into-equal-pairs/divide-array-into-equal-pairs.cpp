class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);
        for (auto num : nums) {
            freq[num]++;
        }

        int freqSum = 0;
        for (auto value : freq) {
            if (value % 2) {
                return false;
            }
        }

        return true;
    }
};