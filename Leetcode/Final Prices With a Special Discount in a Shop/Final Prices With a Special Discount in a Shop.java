// Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, 
// if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and 
// prices[j] <= prices[i], otherwise, you will not receive any discount at all.

// Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.

class Solution {
    public int[] finalPrices(int[] prices) {
        // Traversing each element of price array 
        for(int i = 0 ; i < prices.length - 1; i++){
            // j will be ahead of i as mentioned in the question
            for(int j = i+1 ; j < prices.length ; j++){
                // traverse till we get discount prices[j] <= prices[i]
                if(prices[j] <= prices[i])
                   { 
                       // update price array
                    prices[i] = prices[i]-prices[j];
                   break;
                    }
            }
        }
        // return final price.
    return prices;
    }
}