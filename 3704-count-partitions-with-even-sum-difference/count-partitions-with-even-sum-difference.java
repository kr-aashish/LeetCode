class Solution {
    public int countPartitions(int[] nums) {
        int sum = Arrays.stream(nums).sum();
        int currentSum = nums[0];
        int partitions = 0;
        for (int i = 1; i < nums.length; i++) {
            if ((sum - 2 * currentSum) % 2 == 0) {
                partitions++;
            }
            currentSum += nums[i];
        }
        return partitions;
    }
}