class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, vector<pair<int, int>>> products;
        int numsSize = nums.size();
        int count = 0;
        for (int i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                int product = nums[i] * nums[j];
                products[product].push_back(make_pair(nums[i], nums[j]));
            }
        }
        for (auto product : products) {
            int pairs = product.second.size();
            count += pairs * (pairs - 1) / 2;
        }
        count *= 8;

        return count;
    }
};