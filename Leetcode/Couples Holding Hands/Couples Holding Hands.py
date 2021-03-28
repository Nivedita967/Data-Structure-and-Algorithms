#Problem:https://leetcode.com/problems/couples-holding-hands/description/
class Solution:
    def minSwapsCouples(self, array: List[int]) -> int:
        i=0
        ans=0
        n=len(array)
        while i<n:
            if array[i]%2==0:                #check if cuurent number is even 
                if array[i+1]==array[i]+1: #check if  next number forms a pair if yes the jump two steps and continue 
                    i+=2
                    continue
                else:
                    index=i+1                     # find the number in array which forms the pair and make a swap and increse ans by 1 
                    while array[index]!=array[i]+1:
                        index+=1
                    temp=array[index]
                    array[index]=array[i+1]
                    array[i+1]=temp
                    i+=2
                    ans+=1
            if array[i]%2!=0:                  #if number is not even 
                if array[i+1]==array[i]-1:#check if next number formas a couple 
                    i+=2
                    continue
                else:                                #if they dont form a couple then find the couple in array and make a swap 
                    index=i+1
                    while array[index]!=array[i]-1:
                        index+=1
                    temp=array[index]
                    array[index]=array[i+1]
                    array[i+1]=temp
                    i+=2                        #jump two steps when couple is found and swapped
                    ans+=1
        return (ans)
