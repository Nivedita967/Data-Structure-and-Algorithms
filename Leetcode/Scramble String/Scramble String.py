# We can scramble a string s to get a string t using the following algorithm:

# If the length of the string is 1, stop.
# If the length of the string is > 1, do the following:
# Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
# Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
# Apply step 1 recursively on each of the two substrings x and y.
# Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


class Solution:
    	# Tries to scramble self.start[l1: r1 + 1] into self.target[l2: r2 + 1]
    @lru_cache(maxsize=None)
    def isScrambleHelper(self, l1, r1, l2, r2):
        assert(0 <= l1 and l1 <= r1 and r1 <= len(self.target) - 1)
        assert(0 <= l2 and l2 <= r2 and r2 <= len(self.target) - 1)
        assert(r1 - l1 == r2 - l2)
        
		# Base cases (check for equality)
        areEqual = self.start[l1:r1+1] == self.target[l2:r2+1]
        
        if areEqual:
            return True
        
        if l1 == r1:
            return areEqual
			
		# When equality is not present,  split and continue recursively.
		# Choose a point at which we want to split the start substring.
	   for splitOff in range(r1 - l1):
	   		# First, compute the case in which we do not scramble the start substring.
            answerLeftLeft = self.isScrambleHelper(
                l1, l1 + splitOff,
                l2, l2 + splitOff
            )
            
            if answerLeftLeft:
                answerRightRight = self.isScrambleHelper(
                    l1 + splitOff + 1, r1,
                    l2 + splitOff + 1, r2
                )

                if answerRightRight:
                    return True
            
            # check if maybe scrambling does the job.
            answerLeftRight = self.isScrambleHelper(
                l1, l1 + splitOff,
                r2 - splitOff, r2
            )
            
            if not answerLeftRight:
                continue
			
			
            answerRightLeft = self.isScrambleHelper(
                l1 + splitOff + 1, r1,
                l2, r2 - splitOff - 1
            )
            
            if answerRightLeft:
                return True

        return False

    def isScramble(self, s1: str, s2: str) -> bool:
        assert(len(s1) == len(s2)) 
        self.start = s1
        self.target = s2
        return self.isScrambleHelper(0, len(s1) - 1, 0, len(s1) - 1)