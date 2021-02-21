"""
A python program to implement Mark and Toys
Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money. Given a list of toy prices and an amount to spend, determine the maximum number of gifts he can buy.
Note Each toy can be purchased only once.

"""

n, k = map(int, input().split())
prices = list(sorted(map(int, input().split())))
toys = 0

for price in prices:
    if price <= k:
        k -= price
        toys += 1
    else:
        break

print(toys)

"""
Sample Input/Output:
Example 1:
Input:
7 50
1 12 5 111 200 1000 10
Output:
4

Example 2:
Input:
4 7
1 2 3 4
Output:
3

"""

