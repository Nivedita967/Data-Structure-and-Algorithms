class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        profit=0 #initialize ans variable to 0 to avoid garbage value
        holding=-prices[0]
        for i in range(1,len(prices)): #iterate thrrough the array
            profit=max(profit,holding+prices[i]-fee) #keep adding profit
            holding=max(holding,profit-prices[i])
        return profit