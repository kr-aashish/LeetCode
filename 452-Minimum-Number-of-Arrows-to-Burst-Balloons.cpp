class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<array<int, 2>> coordinates;
        for (auto point : points) 
            coordinates.push_back({point[0], point[1]});

        sort(coordinates.begin(), coordinates.end(),
        [](array<int, 2> pointOne, array<int, 2> pointTwo) {
            return pointTwo[1] > pointOne[1];
        });

        int arrows = 0;
        long long last = -3e18;
        for (auto point : coordinates) {
            if (point[0] > last) {
                arrows++;
                last = point[1];
            }
        }
        return arrows;
    }
};