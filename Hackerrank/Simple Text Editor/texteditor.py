lst=[]
s=""
q=int(input())
for i in range(q):
    inp=input()
    t=inp[0]
    w=inp[2:len(inp)]
    if t=="1":
        lst.append(s)
        s=s+w
    elif t=="2":
        lst.append(s)
        s=s[:-int(w)]
    elif t=="3":
        print(s[int(w)-1])
    elif t=="4":
        s=lst.pop()
    else:
        print(s)