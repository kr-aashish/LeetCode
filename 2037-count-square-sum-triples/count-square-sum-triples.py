class Solution(object):
    def countTriples(self, n):
        """
        :type n: int
        :rtype: int
        """
        A = [a * a for a in range(1, n + 1)]
        B = [b * b for b in range(1, n + 1)]
        C = [c * c for c in range(1, n + 1)]

        count = 0
        for a in A:
            for b in B:
                for c in C:
                    if (a + b == c):
                        count += 1
        return count
        