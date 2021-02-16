int maxProfit(int* prices, int pricesSize)
{
    int min = INT_MAX;
    int max=0;
    for(int i=0; i<pricesSize;i++)
    {
        if(prices[i]<min) //Cheking Min possible value to buy
            min = prices[i];
        else if(max<prices[i]-min) //Find max profit from current Min
            max=  prices[i]-min;
    }
    return max;
}
