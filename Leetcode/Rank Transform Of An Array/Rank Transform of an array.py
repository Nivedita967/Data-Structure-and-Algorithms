class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        
        # copying the original array
        lst = arr[:]
        
        # sorting the array in ascending order
        lst=sorted(lst)
        
        # initializing rank and previous element variable
        prev=float('inf')
        rank=0
        
        # this will map the rank with element
        mapping = dict()
        
        for i in lst:
            # if element is equal to previous element assign same rank
            if i==prev:
                mapping[i]=rank
            
            # otherwise increment the rank and assign the new rank
            else:
                rank+=1
                mapping[i]=rank
                prev=i
        
        # this will store the ranks for original array
        ranks = []
        
        for i in arr:
            # appending the ranks using the dictionary created above
            ranks.append(mapping[i])
            
        return ranks
