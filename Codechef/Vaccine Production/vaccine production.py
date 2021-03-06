d1,v1,d2,v2,x = map(int,input().split())
total = 0
ans = 0
while total < x:
    if d1 == 1:
        total += v1
    else:
        d1 -= 1
    if d2 == 1:
        total += v2
    else:
        d2 -= 1
    ans += 1
print(ans)
