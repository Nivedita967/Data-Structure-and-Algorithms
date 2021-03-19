// We will first generate array containing all the possible values that toppingCosts can generate.
// We know that there a three ways in which a topping can be selected

// Not select , move on to the next topping.
// Select once, move to next
// Select twice, move to next
// Here is the digram how it will look, say for toppingCosts = [3, 4] then our recursion tree would like below at each level each topping having 3 choices.

// We now have all possible values toppingCost can give.
// Following constraints its size can go max upto 3^10 .

// We can now add each baseCost and chech which gives is closest to target.

Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
Output: 10
Explanation: Consider the following combination (all 0-indexed):
- Choose base 1: cost 7
- Take 1 of topping 0: cost 1 x 3 = 3
- Take 0 of topping 1: cost 0 x 4 = 0
Total: 7 + 3 + 0 = 10.

class Solution {
public:
    void solve(int i,vector<int>t,int cost,vector<int> &ans)
    {
        if(i==t.size())
        {
            ans.push_back(cost);
            return;
        }
        
        solve(i+1,t,cost,ans);
        solve(i+1,t,cost+t[i],ans);
        solve(i+1,t,cost+2*t[i],ans);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<int>possible_toppings;
        
        solve(0,toppingCosts,0,possible_toppings);
       
        int diff=INT_MAX,ans;
        for(int i=0;i<baseCosts.size();i++)
        {
            for(int j=0;j<possible_toppings.size();j++)
            {
                int temp=baseCosts[i]+possible_toppings[j];
                
                if(diff>abs(temp-target))
                {
                    diff=abs(temp-target);
                    ans=temp;
                }
                else if(diff == abs(temp-target))
                    ans=min(ans,temp);
            }
        }
        
        return ans;
    }
};