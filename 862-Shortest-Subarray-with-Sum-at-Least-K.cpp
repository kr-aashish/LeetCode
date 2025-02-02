// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        deque<int> dq;
        int minLen = n + 1;
        
        for (int j = 0; j <= n; ++j) {
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                minLen = min(minLen, j - dq.front());
                dq.pop_front();
            }
            // maintaining the monotonic deque
            while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
        }
        
        return minLen <= n ? minLen : -1;
    }
};