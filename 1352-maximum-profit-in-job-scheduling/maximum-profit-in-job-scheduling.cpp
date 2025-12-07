class Solution {
    int findJobEndingJustBefore(int idx, vector<pair<pair<int, int>, int>> &jobs) {
        int lo = 0;
        int hi = idx - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (jobs[mid].first.second <= jobs[idx].first.first) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, 
        vector<int>& profit) {
        int count = profit.size();
        vector<pair<pair<int, int>, int>> jobs(count);
        for (int i = 0; i < count; i++) {
            jobs[i] = {{startTime[i], endTime[i]}, profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](pair<pair<int, int>, int> jobOne, pair<pair<int, int>, int> jobTwo) {
            return jobOne.first.second < jobTwo.first.second;
        });

        vector<int> dp(count, 0);
        dp[0] = jobs[0].second;
        for (int i = 1; i < count; i++) {
            dp[i] = dp[i - 1]; // missing
            int prevIdx = findJobEndingJustBefore(i, jobs);
            if (prevIdx == -1) {
                dp[i] = max(dp[i], jobs[i].second); // missing, dp[i - 1], was taking max of all eventually
            } else {
                dp[i] = max(dp[i], dp[prevIdx] + jobs[i].second); // was doing += dp[prevIdx]
            }
        }

        return dp[count - 1];
    }
};
