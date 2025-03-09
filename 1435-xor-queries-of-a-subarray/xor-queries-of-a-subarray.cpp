class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=0; i<arr.size(); i++) if(i) arr[i] ^= arr[i-1];
        vector<int> ans; 
        for(auto v:queries) {
            int L = v[0], R = v.back();
            int val = arr[R]^(L?arr[L-1]:0);
            ans.push_back(val);
        }
        return ans;
    }
};