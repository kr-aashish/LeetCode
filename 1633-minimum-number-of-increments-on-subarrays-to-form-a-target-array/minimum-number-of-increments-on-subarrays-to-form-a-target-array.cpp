class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int minOperations = target[0];
        for (int i = 1; i < target.size(); i++) {
            minOperations += max(target[i] - target[i - 1], 0);
        }
        return minOperations;
    }
};