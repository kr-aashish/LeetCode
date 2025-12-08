class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());

        int len = nums1.size();
        int minimumProductSum = 0;
        for (int i = 0; i < len; i++) {
            minimumProductSum += nums1[i] * nums2[i];
        }

        return minimumProductSum;
    }
};