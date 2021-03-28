class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        //The idea is that the answer to the problem will be the answer of sliding window for atmost K distinct elements minus answer of sliding window for atmost K-1 distinct elements
        return atMostK(A, K) - atMostK(A, K - 1);
    }
    
    public int atMostK(int[] A, int K) {
        //Initialising answer
        int i = 0, ans = 0;
        //Initialising map
        Map<Integer, Integer> count = new HashMap<>();
        //Looping through the array
        for (int j = 0; j < A.length; ++j) {
            //If we get default value corresponding to the key, we reduce k
            if (count.getOrDefault(A[j], 0) == 0){
                K--;
            } 
            //Then we increase the value for the key
            count.put(A[j], count.getOrDefault(A[j], 0) + 1);
            
            //Looping while K is negative
            while (K < 0) {
                //Decresing value for the key in the map
                count.put(A[i], count.get(A[i]) - 1);
                //If value becomes 0, we incease K
                if (count.get(A[i]) == 0){
                  K++;  
                } 
                //Increasing i
                i++;
            }
            //Updating ans by increasing with (j-i+1)
            ans += j - i + 1;
        }
        //Returning answer
        return ans;
    }
}
