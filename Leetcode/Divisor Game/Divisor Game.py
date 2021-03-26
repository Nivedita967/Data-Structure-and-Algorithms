class Solution(object):
    def divisorGame(self, N):
        """
          We know that if N==1, we cannot choose any x.
         Also, we can always choose x=1 so that if answer for N is true,
         answer for N-1 will be false.
         Thus, Alice will always win if N is even number and if N is odd, she will
        always lose.
        """
        if(N%2==0):
            return True
        
        else:
            return False;
        