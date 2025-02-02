class Solution {
public:
    int numDecodings(string s) {
        int strLen = s.length();
        if (strLen == 1) 
            return (s[0] != '0');

        vector<int> decodingCount(strLen, 0);

        decodingCount[0] = (s[0] != '0');
        if (s[1] != '0')
            decodingCount[1] = decodingCount[0];
        if ((s[0] == '1') or (s[0] == '2' and s[1] != '7' and s[1] != '8' and s[1] != '9'))
            decodingCount[1] += 1;

        for (int i = 2; i < strLen; i++) {
            bool currentDigitNonZero = (s[i] != '0');
            if (currentDigitNonZero) 
                decodingCount[i] = decodingCount[i - 1];

            bool possibleWithPreviousDigitOne = (s[i - 1] == '1');
            bool possibleWithPreviousDigitTwo = (s[i - 1] == '2' and 
                (s[i] != '7' and s[i] != '8' and s[i] != '9'));
            if (possibleWithPreviousDigitOne or possibleWithPreviousDigitTwo)
                decodingCount[i] += decodingCount[i - 2];
        }

        return decodingCount[strLen - 1];
    }
};