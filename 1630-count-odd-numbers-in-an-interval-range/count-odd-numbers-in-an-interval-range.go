func countOdds(low int, high int) int {
    oddCountTillHigh := (high + 1) / 2;
    oddCountTillLow := (low + 1) / 2;
    oddCount := oddCountTillHigh - oddCountTillLow;
    oddCount += low % 2;
    return oddCount;
}