// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05
class Solution {
public:
    long long coloredCells(int n) { return 1 + (long long)n * (n - 1) * 2; }
};