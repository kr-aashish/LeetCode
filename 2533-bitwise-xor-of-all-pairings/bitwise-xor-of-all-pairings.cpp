// https://leetcode.com/problems/bitwise-xor-of-all-pairings
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorNums1 = 0, xorNums2 = 0;

        // XOR all elements in nums1
        for (int num : nums1) {
            xorNums1 ^= num;
        }

        // XOR all elements in nums2
        for (int num : nums2) {
            xorNums2 ^= num;
        }

        // "all pairings of integers between nums1 and nums2"
        // Result depends on the parity of sizes
        int result = 0;
        if (nums2.size() % 2 != 0) {
            result ^= xorNums1;
        }
        if (nums1.size() % 2 != 0) {
            result ^= xorNums2;
        }

        return result;
    }
};