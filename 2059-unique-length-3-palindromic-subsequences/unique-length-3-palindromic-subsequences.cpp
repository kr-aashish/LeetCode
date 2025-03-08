class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // generate all substrings
        set<string> palindromes;
        for (char side = 'a'; side <= 'z'; side++) {
            for (char middle = 'a'; middle <= 'z'; middle++) {
                string palindrome = "";
                palindrome += side;
                palindrome += middle;
                palindrome += side;
                palindromes.insert(palindrome);
            }
        }
        // check for the possiblity of existence and count
        long long count = 0;
        vector<int> position[26];
        for (int i = 0; i < s.length(); i++) {
            position[s[i] - 'a'].push_back(i);
        }
        for (auto palindrome : palindromes) {
            char side = palindrome[0];
            char middle = palindrome[1];

            if (side == middle) {
                if (position[side - 'a'].size() >= 3) {
                    count++;
                }
                continue;
            }
            if (position[side - 'a'].size() < 2) {
                continue;
            }
            int firstIndexForSide = position[side - 'a'][0];
            int lastIndexForSide = position[side - 'a'].back();

            auto it = upper_bound(position[middle - 'a'].begin(), position[middle - 'a'].end(), firstIndexForSide);
            if (it != position[middle - 'a'].end() and *it < lastIndexForSide) {
                count++;
            } 
        }

        return count;
    }
};