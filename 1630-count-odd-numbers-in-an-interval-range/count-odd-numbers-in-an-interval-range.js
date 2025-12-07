/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countOdds = function(low, high) {
    var oddCountTillHigh = Math.floor((high + 1) / 2);
    var oddCountTillLow = Math.floor((low + 1) / 2);
    var oddCount = oddCountTillHigh - oddCountTillLow;
    oddCount += (low % 2);
    return oddCount;
};