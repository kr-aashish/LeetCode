class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> res;
        for(auto x:num) {
            while(!res.empty() and res.top()>x and k>0) {
                res.pop();
                k--;
            }
            res.push(x);
        }
        while(k>0) {
            res.pop();
            k--;
        }
        string ans = "";
        while(!res.empty()) {
            ans += res.top();
            res.pop();
        }
        reverse(ans.begin(), ans.end());
        
        int count = 0;
        while(count<ans.length() and ans[count]=='0') count++;
        
        ans = ans.substr(count);
        if(ans.empty()) return "0";
        
        return ans;
    }
};