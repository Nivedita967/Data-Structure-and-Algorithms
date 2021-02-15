class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A:
            return 0 #If A is empty

        newTail = 0

        for i in range(1, len(A)):
            if A[i] != A[newTail]: #Condition to verify duplicates
                newTail += 1
                A[newTail] = A[i]

        return newTail + 1 #return the value
