"""

Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 4
Print the answer modulo 109+7.


Let “count(n)” be the count of ways to place tiles on a “2 x n” grid, we have following two ways to place first tile. 
1) If we place first tile vertically, the problem reduces to “count(n-1)” 
2) If we place first tile horizontally, we have to place second tile also horizontally. So the problem reduces to “count(n-2)” 
Therefore, count(n) can be written as below. 

   count(n) = n if n = 1 or n = 2
   count(n) = count(n-1) + count(n-2)

"""

def numberOfWays(N):
        # N == 1 
        if(N == 1):
            return 1
        # N ==2
        if(N == 2):
            return 2
        # If we place first tile vertically, the problem reduces to numberOfWays(n-1)”  If we place first tile horizontally, we have to place second tile also horizontally. So the problem reduces to “count(n-2)”
        return numberOfWays(N - 1) + numberOfWays(N - 2);