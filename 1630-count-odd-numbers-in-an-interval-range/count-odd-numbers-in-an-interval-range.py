class Solution:
    def countOdds(self, low: int, high: int) -> int:
        odd_count_till_high = (high + 1) // 2
        odd_count_till_low = (low + 1) // 2
        odd_count = odd_count_till_high - odd_count_till_low
        odd_count += low % 2
        return odd_count