''' A string s ( i.... j ) is said to be palindromic if s[i]==s[j] & s[i++]==s[j--]
We start from the center, continue to expand it to form a larger palindromic string as multiple palindromes have the same center
therefore, 
for an odd length palindromic string , a single character is the center 
for an even length palindromic dtring , a pair of consecutive characters is the center 
'''


class Solution(object):
    def count_sub(self,s,low,high):
        count=0
        while(low>=0 and high<len(s)):
            if(s[low]!=s[high]):
                break
            
            low-=1
            high+=1
            
            count+=1
        
        return count
    
    def countSubstrings(self, s):
        result=0
        n=len(s)
        
        for i in range(n):
            #odd length palindromic string 
            result+=self.count_sub(s,i,i)
            
            #even length palindromic string 
            result+=self.count_sub(s,i,i+1)
        
        return result #final answer
