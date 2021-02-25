"""
A python program to implement Coin Change Problem
Given an amount and the denominations of coins available, determine how many ways change can be made for amount. There is a limitless supply of each coin type.

"""

import sys

def make_change_start(coins, n):
    return make_change(coins, n, 0, {})
    
def make_change(coins, n, index, memo):
    #print("n = {} ind = {}".format(n, index))
    if n == 0:
        return 1
    if index >= len(coins):
        return 0
    key = str(n) + '-' + str(index)
    
    if key in memo:
        return memo.get(key)
    
    res = 0
    amount_with_coin = 0
    while amount_with_coin <= n:
        res += make_change(coins, n - amount_with_coin, index + 1, memo)
        amount_with_coin += coins[index]

    memo.update({key:res})
    return res
    
n,m = input().strip().split(' ')
n,m = [int(n),int(m)]
coins = [int(coins_temp) for coins_temp in input().strip().split(' ')]
print(make_change_start(coins, n))

"""
Sample Input/Output:
Example 1:
Input :
4 3
1 2 3
Output:
4

Example 2:
Input:
10 4
2 5 3 6
Output:
5

"""


