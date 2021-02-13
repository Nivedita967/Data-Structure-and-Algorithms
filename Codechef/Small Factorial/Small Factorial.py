t= input()
prod=1
for index in range(int(t)):
    num=int(input())
    prod=1
    for rang in range(num):
        prod=prod*num
        num-=1
    print(prod)    

