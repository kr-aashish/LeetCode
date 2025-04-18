class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int lenOne = nums1.size();
        int lenTwo = nums2.size();

        int xorVal = 0;
        if (lenTwo % 2) {
            for (auto num : nums1) {
                xorVal ^= num;
            }
        }
        if (lenOne % 2) {
            for (auto num : nums2) {
                xorVal ^= num;
            }
        }

        return xorVal;
    }
};