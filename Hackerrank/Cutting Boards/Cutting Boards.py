"""
Logic:
 We want to minimum cost. First we sort both horizontal and vertical cost array and start with largest element form both array, because cost is derived from total cutting edges multiply with horizontal or vertical cost. 
 So, minimum cost has been derived by minimum cost multiply with cutting edge.

"""
## Cutting Boards  Greedy ###
# t is the number of test cases
t=int(input())
for i in range(t):
    # Input the row & column
    row,column = list(map(int,input().split()))
    xa= list(map(int,input().split()))
    ya= list(map(int,input().split()))
    xa.sort()
    ya.sort()
    xarr=xa[::-1]
    yarr=ya[::-1]
    pivot_x=0
    pivot_y=0
    cost=0
    cutedge_x=1
    cutedge_y=1
    while pivot_x<row-1 and pivot_y<column-1:
        if xarr[pivot_x]>yarr[pivot_y]:   #horizontal cost is greater than vertical cost
            cost+=cutedge_y*xarr[pivot_x]
            cutedge_x+=1
            pivot_x+=1
        else:
            cost+=cutedge_x*yarr[pivot_y]      #vertical cost is greater than horizontal cost
            cutedge_y+=1
            pivot_y+=1
    while pivot_x>=row-1 and pivot_y<column-1:   # adding remaining vertical cost
        cost+=cutedge_x*yarr[pivot_y]
        cutedge_y+=1
        pivot_y+=1
    while pivot_x<row-1 and pivot_y>=column-1:   # adding remaining horizontal cost
        cost+=cutedge_y*xarr[pivot_x]
        cutedge_x+=1
        pivot_x+=1
    print(cost%1000000007)