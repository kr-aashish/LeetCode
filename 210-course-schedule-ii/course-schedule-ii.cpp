class Solution {
public:
    vector<vector<int>> g;
    vector<int> indegree;
    vector<int> v;
    
    void kahns(int N) {
        queue<int> q;
        
        for(int i=0; i<N; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            for(auto x:g[node]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
            
            v.push_back(node);
        }
    }
    
    vector<int> findOrder(int N, vector<vector<int>>& preq) {
        g.resize(N); indegree.assign(N, 0);
        
        for(auto v:preq) {
            int a = v[0], b = v[1];
            g[b].push_back(a);
            indegree[a]++;
        }
        
        kahns(N);
        
        if(v.size() < N) return {};
        
        return v;
    }
};