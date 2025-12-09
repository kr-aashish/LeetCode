func minOperations(nums []int, k int) int {
    var sum int = 0;
    for _, val := range(nums) {
        sum += val;
    }
    return sum % k;
}