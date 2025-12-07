class Solution(object):
    def countPartitions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = sum(nums)
        currSum = nums[0]
        partitions = 0
        for i in range(1, len(nums)):
            if ((total - 2 * currSum) % 2 == 0):
                partitions += 1
        return partitions