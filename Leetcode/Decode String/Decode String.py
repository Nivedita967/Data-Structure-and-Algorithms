# A Program to find a string of different configuration

class Solution:
    def decodeString(self, s: str) -> str:
      
      # A variable to maintain progress
        self.i = 0
        
        # Taking string to be modified
        def decode():
            times = 0
            cur_str = ''
            
            while self.i < len(s):
                c = s[self.i]
                
                # Checking value inside the brackets
                if c == '[':
                    self.i += 1
                    cur_str += times * decode()
                    times = 0
                elif c == ']':
                    return cur_str
                elif c.isdigit():
                    times = times * 10 + int(c)
                elif c.isalpha():
                    cur_str += c
               # Updating the progress 
                self. i += 1
                
            return cur_str
        
        return decode()
