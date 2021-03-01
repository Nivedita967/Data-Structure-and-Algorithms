#TODO: To find maximum amount of gold collected
MAX = 100
  
def maxGold(gold, m, n): 
  
    matrix = [[0 for i in range(n)]                            
                        for j in range(m)]                          #TODO: Creating a matrix
  
    for col in range(n-1, -1, -1):                                  #TODO: Calculating amount
        for row in range(m): 
  
            if (col == n-1): 
                right = 0
            else: 
                right = matrix[row][col+1] 
  
            if (row == 0 or col == n-1): 
                right_up = 0
            else: 
                right_up = matrix[row-1][col+1] 
  
            if (row == m-1 or col == n-1): 
                right_down = 0
            else: 
                right_down = matrix[row+1][col+1] 
  
            matrix[row][col] = gold[row][col] + max(right, right_up, right_down) 
                                                             
    res = matrix[0][0] 
    for i in range(1, m): 
        res = max(res, matrix[i][0])                            #TODO: Calculating maximum amount
  
    return res 
      
gold = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]] 
  
m = 4
n = 4
  
print(maxGold(gold, m, n))                                      #TODO: Printing result
