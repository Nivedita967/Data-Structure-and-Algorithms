#Problem:https://codeforces.com/problemset/problem/298/B
def main():
    # input sail path and direction 
    (t, sx, sy, ex, ey) = map(int, input().split(' '))
    #when starting and ending locations are same, time taken is 0
    if sx == ex and sy == ey:
        return 0
    t = 0 #initiallt time is zero 
    #find earliest time between 2 locations 
    for c in list(input()):
        if sx == ex and sy == ey:
            return t
        #When wind blows to the south 
        if c == 'S':
            if ey < sy:
                sy -= 1
        #When wind blows to the north 
        elif c == 'N':
            if ey > sy:
                sy += 1
        #When wind blows to East 
        elif c == 'E':
            if ex > sx:
                sx += 1
        #When wind blows to West 
        elif c == 'W':
            if ex < sx:
                sx -= 1
        t += 1 #calcuting time here 
    #Stop sailing and return time when they reach ending location
    if sx == ex and sy == ey:
        return t
    return -1
 
print(main())
