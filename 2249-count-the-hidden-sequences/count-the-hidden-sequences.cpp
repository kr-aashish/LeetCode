class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minVal = 0;
        int maxVal = 0;
        int curr = 0;
        for (auto difference : differences) {
            curr += difference;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if (maxVal - minVal > upper - lower) {
                return 0;
            }
        }

        return (upper - lower) - (maxVal - minVal) + 1;
    }
};