function countOdds(low: number, high: number): number {
    let oddCountTillHigh: number = Math.floor((high + 1) / 2);
    let oddCountTillLow: number = Math.floor((low + 1) / 2);
    let oddCount: number = oddCountTillHigh - oddCountTillLow;
    oddCount += (low % 2);
    return oddCount;
};