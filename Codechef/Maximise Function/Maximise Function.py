for _ in range(int(input())):
    # reading number of element in sequnce
    n=int(input())
    
    # reading the sequence
    lst = list(map(int, input().split()))
    
    # sorting the sequence in ascending order
    lst=sorted(lst)
    
    # taking minimum element
    a=lst[0]
    # taking second minimum
    b=lst[1]
    # taking largest element
    c=lst[-1]
    
    # calculating the required result
    result = abs(a-b)+abs(b-c)+abs(c-a)
    
    print(result)
