 def countPalindromicSubsequences(self, S):
        def cache(start, end):            # This function serves to save the result
            if end <= start + 2:          # simple cases can be computed directly
                return end - start
            
            if (start, end) not in check: # if not saved, compute and save before returning
                check[(start, end)] = DFS(start, end)
                
            return check[(start, end)]
        
        def DFS(start, end):     #returns the number of distinct palindromes in S[start:end]
            count = 0
            segment = S[start:end]
            
            for x in 'abcd':
                try:
                    i = segment.index(x) + start  # the starting index in S
                    j = segment.rindex(x) + start # the ending index in S
                except:
                    continue
                    
                count += cache(i+1, j) + 2 if i != j else 1

            return count % 1000000007
                
        check = {}
        return cache(0, len(S))