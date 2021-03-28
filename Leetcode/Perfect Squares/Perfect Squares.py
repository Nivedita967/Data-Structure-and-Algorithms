class Solution:
    def numSquares(self, n: int) -> int:
        
        while( n % 4 == 0 ):
            # Reduction by factor of 4
            n //= 4
            
        if n % 8 == 7:
            # Quick response for n = 8k + 7
            return 4
        
        # Check whether n = a^2 + b^2
        for a in range( int(sqrt(n))+1 ):
            
            b = int( sqrt( n - a*a ) )
            
            if ( a**2 + b ** 2 ) == n :
                return (a>0) + (b>0)
            
        # n = a^2 + b^2 + c^2
        return 3