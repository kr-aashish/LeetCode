class Solution {
public:
    bool isValid(string s) {
            stack<int> st; bool flag = 1;

    for(auto x:s)
    {
        if(x=='(' or x=='{' or x=='[')
            st.push(x);
        else if(!st.empty())
        {
            if(x==')')
            {
                if(st.top()=='(')
                    st.pop();
                else
                {
                    flag=0; 
                }
            }
            if(x=='}')
            {
                if(st.top()=='{')
                    st.pop();
                else
                {
                    flag=0; 
                }
            }
            if(x==']')
            {
                if(st.top()=='[')
                    st.pop();
                else
                {
                    flag=0; 
                }
            }
        }
        else flag = 0;
    }

    return flag && st.empty();
    }
};