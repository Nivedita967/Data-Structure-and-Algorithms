t = int(input())
for _ in range(t):
    
    # Taking spaced integers as input
    N, k, x, y = map(int, input().split())
    if (x==y):
        print(N,N)
    else:
        if (x>y):
            if (x==N):
                onex, oney = y, x
                twox, twoy = 0, N-y
                thirdx, thirdy = twoy, twox
                fourthx, fourthy = x,y
            elif (y==0):
                onex, oney = N, N-x
                twox, twoy = oney, onex
                thirdx, thirdy = 0, N-x
                fourthx, fourthy = x, y
            else:
                fourthx, fourthy = x-y, 0
                onex, oney = N, N-fourthx
                twox, twoy = oney, onex
                thirdx, thirdy = fourthy, fourthx

        else:
            if (y==N):
                onex, oney = x,y
                twox, twoy = x,y
                thirdx, thirdy = x,y
                fourthx, fourthy = x,y
            elif (x==0):
                onex, oney = N-y, N
                twox, twoy = oney, onex
                thirdx, thirdy = N-twoy, 0
                fourthx, fourthy = x,y
            else:
                fourthx, fourthy = 0, y-x
                onex, oney = N-fourthy, N
                twox, twoy = oney, onex
                thirdx, thirdy = fourthy, 0

        # Pattern repeats every four times
        if (k%4 == 1):
            print(onex, oney)
        elif (k%4 == 2):
            print(twox, twoy)
        elif (k%4 == 3):
            print(thirdx, thirdy)
        else:
            print(fourthx, fourthy)

# There is a big pattern behind this problem
# Solved using just mathematics 