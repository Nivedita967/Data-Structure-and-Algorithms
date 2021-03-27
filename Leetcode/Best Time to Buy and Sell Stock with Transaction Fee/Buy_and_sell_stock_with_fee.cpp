/*  Algorithm => 
* In this we use dynamic programming. At each step we store 2 values 
* 1) the buy ending  (i.e. max profit when the current transaction is bought )
* 2) the sell ending  (i.e. max profit when current transaction is sold along with fee)
* For buy ending we get following two subcases:
* When the previous state is maintained i.e. buy_profit = last_buy_profit
* When the previous state was sold and current state is buy i.e. buy_profit = last_sell_profit - prices[i]
* For sell ending we get following two subcases:
* When the previous state is maintained i.e. sell_profit = last_sell_profit
* When the previous state was buy and current state is sell i.e. sell_profit = last_buy_profit + prices[i] - fee
*/

class Solution{
public:
    int maxProfit(vector<int> &prices, int fee){
        int buy_profit = 0, sell_profit = 0, new_buy_profit = 0, new_sell_profit = 0;
        buy_profit -= prices[0];
        for (int i = 1; i < prices.size(); i++){
            new_buy_profit = max(buy_profit, sell_profit - prices[i]);
            new_sell_profit = max(sell_profit, prices[i] + buy_profit - fee);
            buy_profit = new_buy_profit;
            sell_profit = new_sell_profit;
        }
        return sell_profit;
    }
};
