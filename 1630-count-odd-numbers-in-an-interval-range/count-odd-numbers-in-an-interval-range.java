class Solution {
    public int countOdds(int low, int high) {
        int oddCountTillHigh = (high + 1) / 2;
        int oddCountTillLow = (low + 1) / 2;
        int oddCount = oddCountTillHigh - oddCountTillLow;
        oddCount += low % 2;
        return oddCount;
    }
}