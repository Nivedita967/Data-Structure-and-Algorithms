def find(a: int) -> str:
    # return Yes if number have odd divisor else No
    while a % 2 == 0:
        a = a // 2   # half the number until it is not divisible completely by 2
    return 'YES' if a != 1 else 'NO'
 
t=int(input())
k=0
while(k<t):
    n=int(input())
    print(find(n))
    k+=1
    
'''
Example--->
Input:
6
2
3
4
5
998244353
1099511627776
---------------
Output:
NO
YES
NO
YES
YES
NO
'''
