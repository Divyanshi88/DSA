class Solution(object):
    def checkPowersOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n > 0:
            if n % 3 == 2:  # If remainder is 2, we can't represent n as the sum of distinct powers of three
                return False
            n //= 3  # Reduce n by removing the lowest power of 3
        return True
