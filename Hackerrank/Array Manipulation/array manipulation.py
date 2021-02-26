n,m=map(int,raw_input().split())
ch=[0 for _ in xrange(n+2)]
for _ in xrange(m):
    a,b,k=map(int,raw_input().split())
    ch[a]+=k
    ch[b+1]-=k
v=0
m=0
for i in xrange(1,n+1):
    v+=ch[i]
    m=max(m,v)
print m
