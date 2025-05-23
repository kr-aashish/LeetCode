class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (auto task : tasks)
            freq[task]++;

        int ans = 0;
        for (auto task : freq) {
            int count = task.second;

            if (count == 1)
                return -1;

            if (count % 3 == 0)
                ans += count / 3;
            else if (count % 3 == 2 or count % 3 == 1)
                ans += count / 3 + 1;
        }

        return ans;
    }
};