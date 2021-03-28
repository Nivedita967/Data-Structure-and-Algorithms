/*
You would like to make dessert and are preparing to buy the ingredients. You have n ice cream base flavors and m types of toppings to choose from. You must follow these rules when making your dessert:

There must be exactly one ice cream base.
You can add one or more types of topping or have no toppings at all.
There are at most two of each type of topping.
You are given three inputs:

baseCosts, an integer array of length n, where each baseCosts[i] represents the price of the ith ice cream base flavor.
toppingCosts, an integer array of length m, where each toppingCosts[i] is the price of one of the ith topping.
target, an integer representing your target price for dessert.
You want to make a dessert with a total cost as close to target as possible.

Return the closest possible cost of the dessert to target. If there are multiple, return the lower one.

*/
void dp(int* tc, int i, int cost, int t, int best, int toppingCostsSize, int max_top = 2) {
    // If we have reached the end of the top array
    if (cost >= t || i >= toppingCostsSize) {
        if (abs(cost - t) < abs(best - t))
            best = cost;
            // If there are multiple, return the lower one
        else if (abs(best - t) == abs(cost - t))
            best = min(best, cost);            
    }
    else
        for (int j = 0; j <= max_top; ++j)
            // Recusrsion
            dp(tC, i + 1, cost + j * tC[i], t, best);
}
int closestCost(int* baseCosts, int baseCostsSize, int* toppingCosts, int toppingCostsSize, int target) {
    int best = INT_MAX;
    int base;
    for (base = 0 ; base < baseCostsSize ; base++){
         // For Each element of base array run DFS in the top array to find the cost.
         dp(toppingCosts, 0, base, target, best,toppingCostsSize);
    }
       //closest possible cost of the dessert to target
    return best;
}