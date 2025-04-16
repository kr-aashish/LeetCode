class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int pointerOne = m - 1;
        int pointerTwo = n - 1;

        while (index >= 0 and pointerOne >= 0 and pointerTwo >= 0) {
            if (nums1[pointerOne] > nums2[pointerTwo]) {
                nums1[index--] = nums1[pointerOne--];
            } else {
                nums1[index--] = nums2[pointerTwo--];
            }
        }

        while (index >= 0 and pointerOne >= 0) {
            nums1[index--] = nums1[pointerOne--];
        }

        while (index >= 0 and pointerTwo >= 0) {
            nums1[index--] = nums2[pointerTwo--];
        }
    }
};