function countPartitions(nums: number[]): number {
    let sum = nums.reduce((a, b) => a + b, 0);
    let currSum = 0;
    let partitions = 0;
    nums.forEach((val, idx) => {
        if (idx != 0) {
            currSum += val;
            partitions += Number((sum - 2 * currSum) % 2 == 0);
        }
    });
    return partitions;
};