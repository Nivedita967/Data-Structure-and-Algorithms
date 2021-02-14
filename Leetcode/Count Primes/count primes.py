class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Sieve of Eratosthenes

        # We are only interested in numbers LESS than the input number
        # exit early for numbers LESS than 2
        if n < 2:
            return 0
        
        # create strike list for the input range, initializing all indices to prime (1).
        strikes = [1] * n

        # we know that 0 and 1 are not prime
        strikes[0] = 0
        strikes[1] = 0
        
        # Now set multiples of remaining numbers that are marked as prime to
        # not prime.  It is safe ignore numbers alreay marked as not prime
        # because there are factor(s) that divide evenly into this number and
        # all its multiples.  
        for i in range(2, int(n**0.5)+1):
            if  strikes[i] != 0:
                strikes[i*i:n:i] = [0] * ((n-1-i*i)//i + 1)

        return sum(strikes) // returns prime numbers in that range
