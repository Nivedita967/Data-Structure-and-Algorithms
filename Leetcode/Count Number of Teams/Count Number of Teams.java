// There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

// You have to form a team of 3 soldiers amongst them under the following rules:

// Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
// A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
// Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


class Solution {
    public int numTeams(int[] rating) {
        int count = 0;
        // Traversing rating array to make a valid team. 
        for(int i = 0 ; i < rating.length - 2 ; i++){
            // j will start from next to i (rating next to rating of soldier i)
            for(int j = i+1; j < rating.length - 1; j++){
                // k will start from next to j (rating next to rating of soldier j)
                for(int k = j+1; k< rating.length ; k++){
                    // Condition from the question
                    if((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k]))
                       count++;
                }
            }
        }
                       return count;
    }
}