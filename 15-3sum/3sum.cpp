class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int N = a.size();
        sort(a.begin(), a.end());
        set<vector<int>> st;
        
        for(int i=0; i<N-1; i++) {
            int lo = 0; 
            int hi = N-1;
            
            while(lo<i and hi>i) {
                int sum = a[lo] + a[i] + a[hi];
                
                if(sum>0) hi--;
                else if(sum<0) lo++;
                else {
                    st.insert({a[lo],a[i],a[hi]});
                    lo++; hi--;
                }
            }   
         }
        
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
        
    }
};