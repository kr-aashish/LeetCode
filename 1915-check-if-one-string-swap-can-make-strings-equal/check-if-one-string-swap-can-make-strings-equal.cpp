class Solution {
private:
    string getSwappedString(string str, int indexOne, int indexTwo) {
        string swappedStr = str;
        swap(swappedStr[indexOne], swappedStr[indexTwo]);
        return swappedStr;
    }
public:
    bool areAlmostEqual(string s1, string s2) {
        int len = s1.length();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (getSwappedString(s1, i, j) == s2) {
                    return true;
                }
                if (getSwappedString(s2, i, j) == s1) {
                    return true;
                }
            }
        }
        return false;
    }
};