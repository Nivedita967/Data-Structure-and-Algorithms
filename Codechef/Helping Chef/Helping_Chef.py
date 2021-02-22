// Taking input value of n
n=int(input())
// List l
l=[] 
//loop from 0 to n-1
for i in range(n):
    a=int(input()) 
    //checking if n is less than 10 or not and add the output accordingly
    if a<10:
        l.append("Thanks for helping Chef!")   
    else:
        l.append(-1)
for i in l:
    print(i) // print the output stored in list 
