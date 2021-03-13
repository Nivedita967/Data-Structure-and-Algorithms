class Solution {
    //Defining a hashmap
    Map<String, Integer> map = new HashMap<>();
    public int palindromePartition(String s, int k) {
        //If string is empty return 0
        if (s.length() == k){
           return 0;  
        }
        //Finding length of the string
        int len = s.length();
        //Initialsing dp array, this will contain answer for each k if we partition at len
        int[][] dp = new int[k][len + 1];
        //Using helper function for k=0
        for (int i = 0; i < len; ++i){
            dp[0][i + 1] = helper(s.substring(0, i + 1));
        }
        //For all other values of k
        for (int i = 1; i < k; ++i){
            for (int j = i; j <= len; ++j){
                //Initialsing current value
                int cur = Integer.MAX_VALUE;
                //For each length greater than current value of k, ans will be minimum value found between current value and partition at length-1 plus helper for the substring between length-1 and current value of length
                for (int p = j; p >= i; p--){
                    cur = Math.min(cur, dp[i - 1][p - 1] + helper(s.substring(p - 1,j )));
                }
                dp[i][j] = cur;
            }
        }
        //Returning ans
        return dp[k - 1][len];
        
        
    }
    //This is the helper function
    private int helper(String str){
        //If string is empty or null, return 0
        if (str == null || str.length() == 0){
             return 0;
        }
        //If map already contains string 
        if (map.containsKey(str)){
            return map.get(str);
        } 
        //Initialsing ans
        int ans = 0;
        //For the string length,if character from start and end are not equal, then increasing ans
        for (int i = 0; i < str.length(); ++i){
            if (str.charAt(i) != str.charAt(str.length() - i - 1)){
                ans++;
            }
        }
        //Since the string is counted two times in the previous step, ans/2
        ans /= 2;
        //Putting the ans into map
        map.put(str, ans);
        //Returning ans
        return ans;
    }
}
