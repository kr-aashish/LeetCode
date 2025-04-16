class Solution {
    void generateNums(int level, string currStr, string pattern, vector<string> &nums, vector<bool> &vis) {
        if (level == pattern.size()) {
            nums.push_back(currStr);
            return;
        }

        if (pattern[level] == 'I') {
            char value = currStr.back();

            for (char nextValue = value + 1; nextValue <= '9'; nextValue++) {
                if (vis[nextValue - '0']) {
                    continue;
                }

                vis[nextValue - '0'] = true;
                currStr.push_back(nextValue);
                generateNums(level + 1, currStr, pattern, nums, vis);
                currStr.pop_back();
                vis[nextValue - '0'] = false;
            }
        } else {
            char value = currStr.back();

            for (char nextValue = value - 1; nextValue >= '1'; nextValue--) {
                if (vis[nextValue - '0']) {
                    continue;
                }

                vis[nextValue - '0'] = true;
                currStr.push_back(nextValue);
                generateNums(level + 1, currStr, pattern, nums, vis);
                currStr.pop_back();
                vis[nextValue - '0'] = false;
            }
        }
    }

public:
    string smallestNumber(string pattern) {
        vector<string> nums;
        vector<bool> vis(10, false); 
        for (char value = '1'; value <= '9'; value++) {
            vis[value - '0'] = true;
            generateNums(0, string(1, value), pattern, nums, vis);
            vis[value - '0'] = false;
        }
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};