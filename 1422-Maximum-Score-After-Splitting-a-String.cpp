class Solution {
public:
    int maxScore(string s) {
        int zeroCount = 0;
        int oneCount = 0;
        for (auto character : s) {
            zeroCount += (character == '0');
            oneCount += (character == '1');
        }

        int currentZeroCount = 0;
        int currentOneCount = 0;
        int maxScore = 0;
        for (int i = 0; i < int(s.length()) - 1; i++) {
            char character = s[i];
            currentZeroCount += (character == '0');
            currentOneCount += (character == '1');

            maxScore = max(
                maxScore,
                currentZeroCount + (oneCount - currentOneCount)
            );
        }

        return maxScore;
    }
};