class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int length = colors.length();
        int cost = 0;
        for (int i = 0; i < length; i++) {
            int currCost = neededTime[i];
            int sum = currCost;
            int maxCurrCost = currCost;
            int count = 1;
            while (i + 1 < length and colors[i] == colors[i + 1]) {
                i++;
                maxCurrCost = max(maxCurrCost, neededTime[i]);
                sum += neededTime[i];
                count++;
            }
            if (count > 1) {
                cost += (sum - maxCurrCost);
            }
        }

        return cost;
    }
};

// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int length = colors.length();
//         vector<vector<int>> minimumCost(length + 5, vector<int> (length + 5));

//         for (int len = 1; len <= length; len++) {
//             for (int left = 0; left < length; left++) {
//                 int right = left + len - 1;

//                 if (right >= length) {
//                     continue;
//                 }

//                 if (len == 1) {
//                     minimumCost[left][right] = 0;
//                 } else {
//                     minimumCost[left][right] = minimumCost[left + 2][right];
//                     if (colors[left] != colors[left + 1]) {
//                         minimumCost[left][right] += 0;
//                     } else if (colors[left] == colors[left + 1]) {
//                         minimumCost[left][right] += min(neededTime[left], neededTime[left + 1]);
//                     }
//                 }
//             }
//         }

//         return minimumCost[0][length - 1];
//     }
// };