test = int(input())
for t in range(test):
    n = int(input())
    speed = list(map(int,input().split()))
    count = 1
    prev_car_speed = speed[0]
    for i in range(1, n):
        car_speed = speed[i]
        if prev_car_speed >= car_speed:
            prev_car_speed = car_speed
            count += 1
    print(count)