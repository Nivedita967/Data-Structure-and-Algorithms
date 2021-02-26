for _ in range(int(input())):
    # reading number of elements in sequence
    n=int(input())
    
    # reading the sequence
    lst=list(map(int, input().split()))
    
    # if overall sum is atleast 0 then total sum==0 possible otherwise not
    if sum(lst)>=0:
        print('YES')
    else:
        print('NO')
