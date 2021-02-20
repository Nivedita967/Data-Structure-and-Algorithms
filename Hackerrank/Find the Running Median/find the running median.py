import bisect #python supports bisect module
n=int(input())
a=[]
for i in range(n):
    p=int(input())
    bisect.insort(a,p) #This bisect module uses a bisection algorithm to keep a list in sorted order as items are inserted
    if len(a)%2!=0:
        print(a[len(a)//2])
    else:
        print((a[len(a)//2]+a[len(a)//2-1])/2)
