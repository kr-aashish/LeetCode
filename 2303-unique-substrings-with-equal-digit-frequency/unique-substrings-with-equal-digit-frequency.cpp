/* Premium
Description:
Given a digit string s, return the number of unique substrings of s where every digit appears the same number of times.

Example 1:
Input: s = "1212"
Output: 5
Explanation: The substrings that meet the requirements are "1", "2", "12", "21", "1212".
Note that although the substring "12" appears twice, it is only counted once.

Example 2:
Input: s = "12321"
Output: 9
Explanation: The substrings that meet the requirements are "1", "2", "3", "12", "23", "32", "21", "123", "321".

Constraints:
1 <= s.length <= 1000
s consists of digits.
*/

class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        // Set to store unique substrings with equal digit frequency
        unordered_set<string> validSubstrings;

        // Iterate over each possible starting position of a substring
        for (int start = 0; start < n; start++) {
            vector<int> digitFrequency(10, 0);

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < n; end++) {
                digitFrequency[s[end] - '0']++;

                // Variable to store the frequency all digits must match
                int commonFrequency = 0;
                bool isValid = true;

                for (int i = 0; i < digitFrequency.size(); i++) {
                    // Skip digits that are not in the substring
                    if (digitFrequency[i] == 0) continue;

                    if (commonFrequency == 0) {
                        // First digit found, set commonFrequency
                        commonFrequency = digitFrequency[i];
                    }
                    if (commonFrequency != digitFrequency[i]) {
                        // Mismatch in frequency, mark as invalid
                        isValid = false;
                        break;
                    }
                }

                // If the substring is valid, add it to the set
                if (isValid) {
                    string substring = s.substr(start, end - start + 1);
                    validSubstrings.insert(substring);
                }
            }
        }

        // Return the number of unique valid substrings
        return validSubstrings.size();
    }
};