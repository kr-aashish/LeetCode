class Solution {
public:
    vector<vector<int>> g;
    vector<int> indegree;

    vector<int> v;

    void kahns(int n)
    {
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            v.push_back(node);

            for(auto x:g[node])
            {
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        g.resize(numCourses);
        indegree.resize(numCourses);
        
        for(auto x:prerequisites)
        {
            int a = x[0];
            int b = x[1];
            
            g[b].push_back(a);
            indegree[a]++;
        }
        
        kahns(numCourses);
        
        if(v.size()<numCourses)
            return 0;
        
        return 1;
       
    }
};