class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n < 5:
            return 0 #for all numbers less than 5, the number of trailing zeroes is 0
        else:
            return n//5+self.trailingZeroes(n//5) #for any number greater than 5, we need to implement this function recursively till its value becomes less than 5
