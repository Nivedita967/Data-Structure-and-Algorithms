# A program to find longest chunked palindrome decomposition

class Solution(object):
    def longestDecomposition(self, text):
        lens = len(text)
        left = 0
        right = lens - 1
        count = 0
#  Temp is the length of each case        
        temp = 0
        while left < right:
# When there are no equal strings on the left and right sides of the entire string, as in Example 2, there is no palindrome at all.           
            if left + temp > right - temp:
                    count += 1
                    break
            if text[left: left + temp + 1] == text[right - temp: right + 1]:
                
                if left == right - temp:
                    count += 1
                    break
# when there is only tpe in the middle of the scan, although left <right, it is forced to exit
                else:
                    count += 2
                    left = left + temp + 1
                    right = right - temp - 1
                    temp = 0
            else:
                temp += 1

# Returning result after verification
        if left == right:
            count += 1
        return count
