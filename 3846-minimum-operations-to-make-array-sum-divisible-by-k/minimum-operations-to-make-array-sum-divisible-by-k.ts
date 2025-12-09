function minOperations(nums: number[], k: number): number {
    let sum = nums.reduce((a, b) => a + b);
    return sum % k;
};