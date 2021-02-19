for _ in range(int(input())):
    # reading no of cars
    n=int(input())
    
    # reading gasoline in each car
    gasoline = list(map(int, input().split()))
    
    # initially fuel is equal to the car 1
    fuel=gasoline[0]
    
    # this will keep track of distance covered
    distance=0
    
    for i in range(1,n):
        # if fuel <=0 break as car can't move
        if fuel<=0:
            break
        
        # decrease fuel count by -1 for every unit of distance
        fuel-=1
        
        # increment distance for every fuel consumed
        distance+=1
        
        # increment fuel by stealing from the cars
        fuel+=gasoline[i]
        
    # total will be the distance covered + fuel left to travel
    print(distance+fuel)
