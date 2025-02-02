class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x:nums) pq.push(x);
        
        while(k--) {
            int val = pq.top(); pq.pop();
            if(!val) break;
            val = -val;
            pq.push(val);
        }
        
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};