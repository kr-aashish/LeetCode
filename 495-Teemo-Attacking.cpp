class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        vector<pair<int,int>> events;
        for(auto x:timeSeries) {
            events.push_back(make_pair(x, 1));
            events.push_back(make_pair(x+duration, -1));
        }
        
        sort(events.begin(), events.end());
        
        int n = events.size(); 
        int cnt = 0;
        long long ans = 0; 
        for(int i=0; i<n; i++) {
            cnt += events[i].second;
            if(cnt>0 and i+1<n) ans += events[i+1].first-events[i].first;;
        }
        return ans;
    }
};