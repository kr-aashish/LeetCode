// Wrong multiplication logic for counting substrings
class Solution {
public:
    int numberOfSubstrings(string s) {
        int tail = 0;
        int head = -1;
        int len = s.length();

        int substrings = 0;
        int countA = 0;
        int countB = 0;
        int countC = 0;

        while (tail < len) {
            while (head + 1 < len and (!countA or !countB or !countC)) {
                head++;
                countA += s[head] == 'a';
                countB += s[head] == 'b';
                countC += s[head] == 'c';
            } 

            if (countA and countB and countC) {
                // substrings += (tail - 0 + 1) * (len - 1 - head + 1);
                substrings += len - head;
            }

            if (head < tail) {
                tail++;
                head = tail - 1;
            } else {
                countA -= s[tail] == 'a';
                countB -= s[tail] == 'b';
                countC -= s[tail] == 'c';
                tail++;
            }
        }

        return substrings;
    }
};