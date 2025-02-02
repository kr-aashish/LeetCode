class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int numsCount = nums.size();

        vector<int> arr(numsCount + 2, 1);
        for (int i = 1; i <= numsCount; i++) {
            arr[i] = nums[i - 1];
        }
        int arrSize = numsCount + 2;

        vector<vector<int>> maxCoinsForRange(numsCount + 2, vector<int> (numsCount + 2, 0));

        for (int len = 1; len <= arrSize; len++) {
            for (int left = 0; left < arrSize; left++) {
                int right = left + len - 1;

                if (right >= arrSize) {
                    break;
                }

                if (len == 1) {
                    maxCoinsForRange[left][right] = 0;
                } else {
                    for (int mid = left + 1; mid < right; mid++) {
                        maxCoinsForRange[left][right] = max(
                            maxCoinsForRange[left][right],
                            maxCoinsForRange[left][mid] + arr[left] * arr[mid] * arr[right] + maxCoinsForRange[mid][right]
                        );
                    }
                }
            }
        }

        return maxCoinsForRange[0][numsCount + 1];
    }
};