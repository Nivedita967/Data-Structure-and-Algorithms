#A list to store history of the string; Accessed when using undo command
lst=[]

#Empty string to store inputs later
s=""

#Number of commands
q=int(input())

#Iteration using q
for i in range(q):
    #Command type {1,2,3,4}+argument
    inp=input()
    #Seperates command and argument
    t=inp[0]
    w=inp[2:len(inp)]
    #To append characters
    if t=="1":
        lst.append(s)
        s=s+w
    #To delete last n characters
    elif t=="2":
        lst.append(s)
        s=s[:-int(w)]
    #To print the nth character
    elif t=="3":
        print(s[int(w)-1])
    #To undo
    elif t=="4":
        s=lst.pop()
    else:
        pass