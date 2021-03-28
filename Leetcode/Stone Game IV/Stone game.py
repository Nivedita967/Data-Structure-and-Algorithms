
#Python program for stone game
class Solution(object):
    def winnerSquareGame(self, n):
         # dynamic programming table for start value from 0 to n
        optimal_play = [ False for _ in range(n+1) ]
        
        # update dynamic programming table for each number in bottom-up order
        for number in range(1, n+1):
            
            # Alice can win with number if there exist a square value i^2 such that optimal_play of number-i^2 cannot win always.
            optimal_play[number] = not all( optimal_play[number-i**2] for i in range(1, int(number**0.5)+1 ))
        
        
        # Check whether Alice can win with start number n
        return optimal_play[n]

        