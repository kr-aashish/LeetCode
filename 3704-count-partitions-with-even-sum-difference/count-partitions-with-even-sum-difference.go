func countPartitions(nums []int) int {
    sum := 0;
    for _, val := range(nums) {
        sum += val
    }

    currSum := 0
    partitions := 0
    for idx, val := range(nums) {
        if idx == 0 {
            continue;
        }
        
        currSum += val
        if (sum - 2 * currSum) % 2 == 0 {
            partitions++;
        }
    }

    return partitions;
}