// https://leetcode.com/problems/valid-square/
// *min_element(distSq.begin(), distSq.end())
// *max_element(distSq.begin(), distSq.end())

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<long long> distSq;
        
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];
                long long sq = dx * dx + dy * dy;
                if (sq == 0) 
                    return false;
                distSq.insert(sq);
            }
        }
        
        if (distSq.size() != 2) 
            return false;
        
        long long side_sq = *min_element(distSq.begin(), distSq.end());
        long long diag_sq = *max_element(distSq.begin(), distSq.end());
        
        return diag_sq == 2 * side_sq;
    }
};