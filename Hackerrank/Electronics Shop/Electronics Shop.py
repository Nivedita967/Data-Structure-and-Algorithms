#Problem:https://www.hackerrank.com/challenges/electronics-shop/problem

s, n, m = list(map(int, input().split()))
keyboard = list(map(int, input().split()))
drive = list(map(int, input().split()))

ans = -1

#For every pair for keyboard and drive,if 
#money spent is larger, return the cost of total cost of that pair 
for k in keyboard:
    for mo in drive:
        if s >= k + mo > ans:
            ans = k + mo
print(ans)
