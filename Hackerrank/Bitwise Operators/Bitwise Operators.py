n = int(input()) #take input
k = int(input()) #take input

#initialize variables
c = 0
d = 0
e = 0
b = n
#c d and e will store and or and xor results repectively.
#iterate the loop
for a in range(n):
    b = n
    while b > a: #iterate from end i.e b = n
        if a&b<k and a&b>c:
            c = a&b
        if a|b<k and a|b>d:
            d = a|b
        if a^b<k and a^b>e:
            e = a^b
        b = b -1

#print results
print(c)
print(d)
print(e)