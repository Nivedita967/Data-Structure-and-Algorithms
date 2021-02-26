# Python function to print leaders in array 
def printLeaders(l, size): 
    m=[]
    max_element = l[size-1]  
    m.append(max_element)     
    for i in range(size-2, -1, -1):         
        if max_element <= l[i]: 
            m.append(l[i])
            max_element = l[i] 
            
    for k in range(len(m)-1,-1,-1):  #get the elements according to their first occurence in the arr
        print(m[k],end=" ")
          
# Driver function 
arr = [16, 17, 4, 3, 5, 2] 
printLeaders(arr, len(arr))
