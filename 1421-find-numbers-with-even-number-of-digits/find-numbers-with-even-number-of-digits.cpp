class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto num : nums) {
            string numAsString = to_string(num);
            count += numAsString.size() % 2 == 0;
        }
        return count;
    }
};