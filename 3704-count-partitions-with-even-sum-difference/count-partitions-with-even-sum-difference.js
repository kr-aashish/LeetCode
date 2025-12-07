/**
 * @param {number[]} nums
 * @return {number}
 */
var countPartitions = function(nums) {
    var sum = nums.reduce((a, b) => a + b, 0);
    var currSum = 0;
    var partitions = 0;
    nums.forEach((val, idx) => {
        if (idx != 0) {
            currSum += val;
            partitions += (sum - 2 * currSum) % 2 == 0;
        }
    });
    return partitions;
};