class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int> candies(sz, 1);
        for (int i = 1; i < sz; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = sz - 1; i >= 1; i--) {
            if (ratings[i - 1] > ratings[i]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};