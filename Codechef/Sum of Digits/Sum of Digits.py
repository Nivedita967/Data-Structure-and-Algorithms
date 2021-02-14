# compute sum of digits
# number

# get sum of digits
t=int(input())
for i in range(t):
   n=int(input())
   a = 0
   while (n>0):
      d=n%10
      a=a+d
      n=n//10
   print(a)