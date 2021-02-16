
def xorOperation(self, n: int, start: int) -> int:
        nums=[] #list to store numbers based on the given condition
        for i in range(n): #iterates from 0 to n-1
            k=start+(2*i)
            nums.append(k) #adding every k at the end of num 
            
        res = reduce(lambda x, y: x ^ y, nums) #applying Xor operation and calculates like((((0^2)^4)^6)^8). 
        print(res)
        
xorOperation(0,10,5)