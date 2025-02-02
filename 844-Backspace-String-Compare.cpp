string process(string s) {
    stack<char> st; 
    for(auto x:s) {
        if(!st.empty() and x=='#') {
            st.pop();
            continue;
        }
        if(x!='#') st.push(x);
    }
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return process(s)==process(t);
    }
};