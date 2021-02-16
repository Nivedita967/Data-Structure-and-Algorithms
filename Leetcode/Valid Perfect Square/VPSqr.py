"""
Python program to check A number given is Valid Perfect Square or not
If the number is Perfect Square it returns true else it returns false

"""

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        ld = num % 10;
        if(ld == 2 or ld==3 or ld== 7 or ld == 8):
            return False;
        
        l = 1;
        r = num;
        while(l <= r):
            mid = int(l + (r-l)/2);
            sq = mid*mid;
            if(sq == num):
                return True;
            elif(sq < num):
                l = mid + 1;
            else:
                r = mid - 1;
        return False;
   
"""
Sample Case:
Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

"""
