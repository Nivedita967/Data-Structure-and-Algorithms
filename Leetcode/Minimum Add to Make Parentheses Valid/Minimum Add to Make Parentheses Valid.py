class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []                      # Creating a stack
        if len(S)==0:
            return 0
        
        stack = [S[0]]
        for i in range(1,len(S)):      # Updating stacks according to the input
            if stack and stack[-1]=='(' and S[i]==')':
                stack.pop()
            else:
                stack.append(S[i])
                
        return len(stack)              # Returning result
