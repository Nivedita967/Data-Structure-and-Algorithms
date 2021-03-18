# Getting number of strings to be provided
t=int(input())

lis = []

# Getting marks
for i in range(t):
    lis.append(int(input()))
    
gender = input()

# Getting sex(b:boy,g:girl)
if gender == 'b':
    ini = 0
else:
    ini = 1
    
su = 0
# Calculating sum of marks
while ini < len(lis):
    su += lis[ini]
    ini += 2

# Printing result
print(su)
    
    

