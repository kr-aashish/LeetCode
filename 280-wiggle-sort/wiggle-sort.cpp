class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0 ; i < int(nums.size()) - 1; i++) {
            bool isEvenIdx = i % 2 == 0;
            bool isOddIdx = !isEvenIdx;
            if ((isEvenIdx and nums[i] > nums[i + 1]) or
                (isOddIdx and nums[i] < nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};