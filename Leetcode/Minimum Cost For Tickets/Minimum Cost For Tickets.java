class Solution {

    public int mincostTickets(int[] days, int[] costs) {
      // Finding the last travel day
    int lastDay = days[days.length - 1]; 
    // dp array will contain the answers for i days
    int[] dp = new int[lastDay + 1]; 
    boolean[] isTravelDay = new boolean[lastDay + 1];
    //marking all the day that we are travelling
    for(int day : days) isTravelDay[day] = true;
    
        //Traversing through all days till lastDay
    for(int i = 1; i <= lastDay; i++) {
        // If not a travel day, we will not buy a ticket
        if(!isTravelDay[i]) { 
            dp[i] = dp[i - 1];
            continue;
        }
       // Checking for all the cases to minimum amount
        dp[i] = costs[0] + dp[i - 1]; // 1-day
        dp[i] = Math.min(costs[1] + dp[Math.max(i - 7, 0)], dp[i]); // 7-day
        dp[i] = Math.min(costs[2] + dp[Math.max(i - 30, 0)], dp[i]); // 30-day
    }
        //Returning the answer for given input
    return dp[lastDay]; 
    }
}
