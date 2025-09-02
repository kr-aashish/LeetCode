class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = points.size();
        int numberOfPairs = 0;
        
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                auto pointOne = points[i];
                auto pointTwo = points[j];

                int x1 = pointOne[0];
                int y1 = pointOne[1];
                int x2 = pointTwo[0];
                int y2 = pointTwo[1];

                if ((x1 - x2) * (y1 - y2) > 0) {
                    continue;
                }

                int minX = min(x1, x2);
                int maxX = max(x1, x2);
                int minY = min(y1, y2);
                int maxY = max(y1, y2);

                bool isValid = true;
                for (auto point : points) {
                    if (point == pointOne or
                        point == pointTwo) {
                        continue;
                    }

                    int x = point[0];
                    int y = point[1];

                    if (x >= minX and x <= maxX and 
                        y >= minY and y <= maxY) {
                        isValid = false;
                    }
                }
                numberOfPairs += isValid;
            }
        }

        return numberOfPairs;
    }
};