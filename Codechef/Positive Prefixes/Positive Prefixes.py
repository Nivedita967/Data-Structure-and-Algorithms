for _ in range(int(input())):
    # reading input in space separated form
    n,k = map(int, input().split())
    
    # this will store the required sequence
    arr=[]

    if k <= (n/2):
        for i in range(1,n+1):
            
            # i less than equal to twice of k and i is odd append i otherwise append -i
            if i<=2*k and i%2==1:
                arr.append(i)
            else:
                arr.append(-i)
    else:
        for i in range(1,n+1):
            
            # if i less than equal to twice of (n-k) and i is even append -i otherwise append i
            if i<=2*(n-k) and i%2==0:
                arr.append(-i)
            else:
                arr.append(i)
    
    # printing array in space separated form
    print(*arr)
