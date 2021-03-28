class Solution:
    def findKthNumber(self, m, n, k):
        if n<m:
            # We loop over "m", so it's better to pick the smallest number
            m,n = n,m 
        def enough(x):
            # Res: Final answer
            res  = 0 
            for a in range(1,m+1):
                # b: Entries in row=a lower than x
                b = min(n, x//a)
                if not b:
                    # "a" values have grown too large (we will get only "0s" from now on)
                    break
                res += b
            return res
        
        # i,j: Lower and Upper Bounds respectively
        i,j = 1,m*n
        # Binary Search
        #    Notes: 1) Our "enough(x)" function counts how many numbers are lower or equal than "x".
        #              Sometimes the multipliciation tables have gaps, so multiple "x" values
        #              can have the same total count.
        #              One example are the numbers x = [126,127] for (m,n,k) = (42,34,401)
        
        #           2) To prevent the issue above, we must look for the lowest value of "x" with
        #              "k" numbers lower of equal.
        #              This principle is embedded into the binary search function.
        while i<j:
            mid  = (i+j)//2
            pos  = enough(mid)
            if pos<k:
                i = mid + 1
            else:
                j = mid # pos>=k is good
        return i
