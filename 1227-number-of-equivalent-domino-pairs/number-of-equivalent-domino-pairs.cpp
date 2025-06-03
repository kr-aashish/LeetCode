class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> freq;
        int numEquivDominoPairs = 0;
        for (auto domino : dominoes) {
            int one = min(domino[0], domino[1]);
            int two = max(domino[0], domino[1]);
            int value = 10 * one  + two;

            numEquivDominoPairs += freq[value];
            freq[value]++;
        }
        return numEquivDominoPairs;
    }
};