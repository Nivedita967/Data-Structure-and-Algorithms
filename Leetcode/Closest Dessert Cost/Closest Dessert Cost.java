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

class Solution {
    // Initialize min to the max value initially.
    int min = Integer.MAX_VALUE;
    int ans=0;
    
    public int closestCost(int[] base, int[] top, int target) {
        //Traverse each element of the base array
        for(int i=0;i<base.length;i++){
            // For Each element of base array run DFS in the top array to find the cost.
            dfs(top,0,target,base[i]);
        }
        return ans;
    }
    
    private void dfs(int [] top,int i,int target,int sum){
        // If we have reached the end of the top array
        if(i>=top.length){
            int diff = Math.abs(sum-target);
            if(diff<min){
                min = diff;
                ans = sum;
            }
            if(diff==min){
                ans = Math.min(ans,sum);
            }
            return;
        }
        
        // Perform DFS for only one base & no topping
        dfs(top,i+1,target,sum);
        // Perform DFS for one base & one topping
        dfs(top,i+1,target,sum+top[i]);
        // Perform DFS for one base & two topping
        dfs(top,i+1,target,sum+2*top[i]);
        
    }
}