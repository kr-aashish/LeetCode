class Solution {
    //front me add krna hai -> custom string ko back me append karo

    string createCustomStr(string str) {
        string customStr = str + "#";
        reverse(str.begin(), str.end());
        customStr += str;

        return customStr;
    }

vector<int> getKmpArray(string str) {
    int n = str.length();
    vector<int> kmpArray(n + 1);

    kmpArray[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        while (j != -1 and str[i] != str[j]) j = kmpArray[j];
        j++, i++;
        kmpArray[i] = j;
    }

    return kmpArray;
}

public:
    string shortestPalindrome(string s) {
        string customStr = createCustomStr(s);
        vector<int> kmp = getKmpArray(customStr);
        int idx = kmp.back();
        
        string reversedStr = s.substr(idx);
        reverse(reversedStr.begin(), reversedStr.end());

        return reversedStr + s;
    }
};