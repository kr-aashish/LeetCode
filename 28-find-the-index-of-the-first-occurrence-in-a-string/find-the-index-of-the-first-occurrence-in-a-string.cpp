class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = needle + "#" + haystack;
        
        int n = s.length();
        int kmp[n+1];
        
        int i = 0, j = -1; kmp[0] = -1;
        while(i<n) {
            while(j!=-1 and s[i]!=s[j]) j = kmp[j];
            j++; i++;
            kmp[i] = j;
        }
        
        
        int idx = 0, ans = -1;
        for(int i=1; i<=n; i++) {
            if(kmp[i] == needle.length()) {
                idx = i; 
                break;
            }
        }
        
        if(idx) ans = idx - (needle.length()+1) -1 - needle.length()+1;
        return ans;
    }
};