// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int target = graph.size() - 1;
        queue<vector<int>> q;
        q.push({0});
        
        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            
            int lastNode = path.back();
            if (lastNode == target) {
                result.push_back(path);
                continue;
            }
            
            for (int neighbor : graph[lastNode]) {
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
        
        return result;
    }
};