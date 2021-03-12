# We have to count the number of cars which were moving at their maximum speed on the straight segment.


test = int(input())       # input test cases
for t in range(test):
    n = int(input())      # taking the number of cars
    speed = list(map(int,input().split()))
    count = 1
    prev_car_speed = speed[0]
    for i in range(1, n):         # Calculating the number of cars at their maximum speed
        car_speed = speed[i]
        if prev_car_speed >= car_speed:
            prev_car_speed = car_speed
            count += 1
    print(count)                  # Printing the result