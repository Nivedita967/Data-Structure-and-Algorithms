# Python program to find length of the longest valid substring
 
class Solution: 
 def longestValidParentheses(self,string):
     n = len(string)

     # Create a stack and push -1
     stack_ = []
     stack_.append(-1)

     # Initialize result
     result = 0

     # Traverse all characters of given string
     for i in range(n):

         # If "(" then,..push index of it
         if string[i] == '(':
             stack_.append(i)

         # If ")",then..
         else:   

             # Pop the previous opening bracket's index
             if len(stack_) != 0:
                stack_.pop()

             # Check if this length formed with base of
             # current valid substring is more than max 
             if len(stack_) != 0:
                 result = max(result, 
                              i - stack_[len(stack_)-1])

             # If stack is empty. push current index as
             # base for next valid substring (if any)
             else:
                 stack_.append(i)

     return result
