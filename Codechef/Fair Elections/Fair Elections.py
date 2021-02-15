for _ in range(int(input())):
    
    # reading packs for john and jack
    n,m = map(int,input().split())
    
    # storing votes of john
    john= list(map(int, input().split()))
    
    # storing votes of jack
    jack= list(map(int, input().split()))
    
    # sorting votes of john in ascending order
    john=sorted(john)
    # sorting votes of jack in descending order
    jack=sorted(jack,reverse=True)
    
    # if current sum of john votes is greater than jack's, no operations required
    if sum(john) > sum(jack):
        print(0)
    else:
        flag=0
        count=0
        
        # swapping the votes until sum of john's votes is not greater than jack's votes
        for i in range(min(n,m)):
            # swapping the votes
            john[i],jack[i]=jack[i],john[i]
            
            # incrementing the opeartion count
            count+=1
            
            # checking if sum of john's votes is greater than jack's
            if sum(john)>sum(jack):
                flag=1
                break
        
        # if flag is set to 1 than it is possible to make John Win otherwise not
        if flag==1:
            print(count)
        else:
            print(-1)
