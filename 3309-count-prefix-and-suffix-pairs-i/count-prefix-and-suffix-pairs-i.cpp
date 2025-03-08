class Solution {
    bool isSuffix(string child, string parent) {
        if (parent.length() < child.length()) {
            return false;
        }

        int parentLen = parent.length();
        reverse(child.begin(), child.end());
        for (int i = 0; i < child.length(); i++) {
            if (child[i] != parent[parentLen - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isPrefix(string child, string parent) {
        if (parent.length() < child.length()) {
            return false;
        }

        for (int i = 0; i < child.length(); i++) {
            if (child[i] != parent[i]) {
                return false;
            }
        }
        return true;
    }

    bool isPrefixAndSuffixPairs(string child, string parent) {
        return isPrefix(child, parent) and isSuffix(child, parent);
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int len = words.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                count += isPrefixAndSuffixPairs(words[i], words[j]);
            }
        }
        return count;
    }
};