# This the pattern regarding the bits.
di = {0:'a',1:'b',2:'c',3:'d',4:'e',5:'f',6:'g',7:'h',8:'i',9:'j',10:'k',11:'l',12:'m',13:'n',14:'o',15:'p'}

t = int(input())
for _ in range(t):
    n = int(input())
    string = str(input())
    ans = ''

    # This will convert the binary number of length 4
    # into integer and map with the dictionary
    for i in range(0,n,4):
        ans += di[int(string[i:i+4],2)]
    print(ans)
