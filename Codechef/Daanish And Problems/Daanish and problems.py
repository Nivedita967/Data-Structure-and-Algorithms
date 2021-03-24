t=int(input()) #test casess
while(t):
    
    a=list(map(int,input().split())) #take list input
    k=int(input())
    
    for i in range(9,-1,-1): #iterate
        
        a[i]=a[i]-k
        
        k=-1*a[i]
        
        if a[i]>0:
            break
    
    print(i+1) #print output
    
    
    t=t-1 #decrement test case value