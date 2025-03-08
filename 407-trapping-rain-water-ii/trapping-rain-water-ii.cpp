// https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-01-19
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // Add all the boundary cells to the priority queue
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i * n);
            pq.emplace(heightMap[i][n - 1], i * n + n - 1);
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            pq.emplace(heightMap[0][j], j);
            pq.emplace(heightMap[m - 1][j], (m - 1) * n + j);
            visited[0][j] = visited[m - 1][j] = true;
        }

        int trappedRainWater = 0;
        vector<int> directions = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            int x = pos / n;
            int y = pos % n;

            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d];
                int ny = y + directions[d + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    trappedRainWater += max(0, height - heightMap[nx][ny]);
                    pq.emplace(max(height, heightMap[nx][ny]), nx * n + ny);
                    visited[nx][ny] = true;
                }
            }
        }

        return trappedRainWater;
    }
};
