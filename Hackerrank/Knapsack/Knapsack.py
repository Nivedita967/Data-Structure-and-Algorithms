
# Getting number of test cases
t=int(input())
for _ in range(t):
    lst=[int(i) for i in input().split()]       # Getting length and target sum
    goal=lst[1]
    nums=[int(i) for i in input().split()]      # Getting spaced numbers
    dyno=[0]
    dyno += [-1]*goal
    for i in range(len(dyno)):                  # Calculating result
        tmp=-1
        largest_x=-1
        val=0
        for x in nums:
            if i-x >= 0 and dyno[i-x]+x>=val:
                tmp=i-x
                largest_x=x
                val=dyno[i-x]+x
        if tmp<0:                             
            dyno[i]=0
        else:
            dyno[i]=largest_x+dyno[tmp]

    print(dyno[-1])                            # Printing result
