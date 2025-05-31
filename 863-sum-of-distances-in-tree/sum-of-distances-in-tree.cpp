class Solution {
    vector<vector<int>> graph;
    vector<int> count;
    vector<int> sumOfDistances;
    int N;

    void depthFirstSearchOne(int node, int parentNode) {
        count[node] = 1;

        for (auto neigh : graph[node]) {
            if (neigh != parentNode) {
                depthFirstSearchOne(neigh, node);
                count[node] += count[neigh];
                sumOfDistances[node] += sumOfDistances[neigh] + count[neigh];
            }
        }
    }

    void depthFirstSearchTwo(int node, int parentNode) {
        for (auto neigh : graph[node]) {
            if (neigh != parentNode) {
                sumOfDistances[neigh] = sumOfDistances[node] - count[neigh] + N - count[neigh];
                depthFirstSearchTwo(neigh, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        graph.resize(n);
        count.resize(n);
        sumOfDistances.resize(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        depthFirstSearchOne(0, -1);
        depthFirstSearchTwo(0, -1);

        return sumOfDistances;
    }
};