class Solution:
    def getOddOccurrence(self, arr, n):
        res = 0   # Initialize result
      
        # Traverse the array 
        for element in arr: 
          
            res = res ^ element   # XOR with the result 
  
        return res 
  
/* Test array 
1.)  arr = [ 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2] 
     Output : 3
    
2.)  arr = [5, 7, 2, 7, 5, 2, 5]
     Output : 5
